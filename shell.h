#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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


#endif
