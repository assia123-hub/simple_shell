#include "shell.h"

char* _getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    }

    n = getline(&line, &len, stdin);

    if (n == -1)
    {
        free(line);
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
         else
         {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        free(line);
        line = NULL;
    }

    return line;
}
