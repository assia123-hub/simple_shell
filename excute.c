#include "shell.h"

int execute(char **arguments)
{
    int status = 0;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        if (execve(arguments[0], arguments, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
    }

    return status;
}
