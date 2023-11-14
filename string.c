#include "shell.h"

void _putchar(char c) {
    write(1, &c, 1);
}

char *_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }

    char *res = malloc(i * sizeof(char));
    if (res == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t j = 0; j <= i; j++) {
        res[j] = str[j];
    }

    return res;
}

char *_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
}
