#include "shell.h"

void _puts(char *str) {
    while (*str) {
        _putchar(*str++);
    }
}

int _putchar(char c) {
    return write(STDOUT_FILENO, &c, 1);
}

char *_strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *res = malloc(len);
    if (!res) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return strcpy(res, str);
}

char *_strchr(const char *str, int c) {
    while (*str != (char)c) {
        if (*str == '\0') {
            return NULL;
        }
        str++;
    }
    return (char *)str;
}

