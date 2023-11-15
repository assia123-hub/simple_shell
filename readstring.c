#include "shell.h"

char *read_string(void)
{
char *string = NULL;
size_t len = 0;
ssize_t n;
n = getline(&line, &len, stdin);
return (string);
}
