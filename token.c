#include "shell.h"

char **tokenizer(char *line) {
    if (!line) {
        return NULL;
    }

    char **command = NULL;
    int cpt = 0;

    for (char *token = strtok(_strdup(line), " \t\n"); token; token = strtok(NULL, " \t\n")) {
        cpt++;
    }

    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, " \t\n");
    for (int i = 0; token; token = strtok(NULL, " \t\n"), i++) {
        command[i] = _strdup(token);
    }

    command[cpt] = NULL;

    return command;
}
