#include "shell.h"
/**
 * main - Entry point for the simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	while (1)
	{
		char *line = _getline();

		if (line == NULL || line[0] == '\0')
		{
			free(line);
			continue;
		}

		char **arguments = tokenizer(line);

		free(line);

		if (arguments != NULL && arguments[0] != NULL)
		{
			int status = execute(arguments);

			printf("Exit status: %d\n", status);

			for (int i = 0; arguments[i] != NULL; i++)
			{
				free(arguments[i]);
			}
			free(arguments);
		}
		else
		{
			for (int i = 0; arguments[i] != NULL; i++)
			{
				free(arguments[i]);
			}
			free(arguments);
		}
	}
	return (0);
}

