#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/*---PROTOTYPES---*/
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char* _getline(void);
char **my_split(char *line);

int tokenize_input(const char *input, char *args[]);
void execute_command(char *args[]);

#endif
