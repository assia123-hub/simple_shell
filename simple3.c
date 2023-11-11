#include "shell.h"

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */

int path_cmd(char **cmd) {
    char *path, *value, *cmd_path;
    struct stat buf;

    path = _getenv("PATH");
    value = _strtok(path, ":");
    while (value != NULL) {
        cmd_path = build(*cmd, value);
        if (stat(cmd_path, &buf) == 0) {
            *cmd = _strdup(cmd_path);
            free(cmd_path);
            free(path);
            return 0;
        }
        free(cmd_path);
        value = _strtok(NULL, ":");
    }
    free(path);

    return (path);
}

/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value) 
{
    size_t len = _strlen(value) + _strlen(token) + 4;

    char *ar = malloc(len);
    if (ar == NULL) 
    {
        return NULL;
    }

    _strcat(_strcat(_strcat(ar, value), "/"), token);

    return ar;
}
