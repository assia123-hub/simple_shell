#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stddef.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>

/*---PROTOTYPES---*/
char *full_path(char *start, char *command, struct stat *s);
char *_path(char *command);
char *_getpath_alternative(char *command);
char* _getline(void);
int execute(char **arguments);
char **tokenizer(char *line);

/*---string---*/
void _putchar(char c);
char *_strdup(const char *str);
char *_strchr(const char *str, int c);

#endif
