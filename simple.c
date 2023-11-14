#include <stdlib.h>
#include <string.h>
#include "main.h"

char *_getpath_alternative(char *command) {
    struct stat st;

    if (command[0] == '/' && stat(command, &st) == 0) {
        return strdup(command);
    }

    char *path_env = getenv("PATH");
    if (!path_env) {
        return NULL;
    }

    char *path_copy = strdup(path_env);
    if (!path_copy) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *dir_start = path_copy;
    char *dir_end;
    while ((dir_end = strchr(dir_start, ':')) != NULL || *dir_start != '\0') {
        size_t dir_len = (dir_end != NULL) ? (size_t)(dir_end - dir_start) : strlen(dir_start);

        size_t full_cmd_len = dir_len + 1 + strlen(command) + 1;
        char *full_cmd = malloc(full_cmd_len);
        if (!full_cmd) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strncpy(full_cmd, dir_start, dir_len);
        full_cmd[dir_len] = '/';
        strcpy(full_cmd + dir_len + 1, command);

        if (stat(full_cmd, &st) == 0) {
            free(path_copy);
            return full_cmd;
        }

        free(full_cmd);

        if (dir_end != NULL) {
            dir_start = dir_end + 1;
        } else {
            break;
        }
    }

    free(path_copy);
    return NULL;
}

