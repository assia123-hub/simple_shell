#include "shell.h"

char *read_string(void)
{
char *line = NULL;
size_t len = 0;
ssize_t n;
write(STDOUT_FILENO, "$ ", 2);
n = getline(&line, &len, stdin);
if (n == -1)
{
free(string);
return NULL;
}
return line;
}
