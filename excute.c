#include "shell.h"

int execute(char **arguments) 
{
    pid_t child_pid = fork();

    if (child_pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) 
    {
        if (execvp(arguments[0], arguments) == -1) 
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } 
    else 
    {
        int status;
        waitpid(child_pid, &status, 0);
        return status;
    }
    return -1;
}
