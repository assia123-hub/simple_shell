#include "shell.h"
/**
 * get_line - Read a line of input from the user.
 *
 * Return: A dynamically allocated string containing the input line.
 */
char *get_line(void)
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
	}
	return (line);
}
