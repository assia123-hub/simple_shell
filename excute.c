#include "shell.h"

/**
 * execute - Create a child process and execute a command.
 * @arguments: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
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
	return (status);
	}
	return (-1);
}
