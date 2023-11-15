#include "shell.h"
/**
 * tokenizer - Tokenize a string into an array of strings.
 * @line: The input string to tokenize.
 *
 * Return: An array of strings containing the tokens.
 */
char **tokenizer(char *line)
{
	if (!line)
		return (NULL);
	char **command = NULL;
	int token_count = 0;
	char *line_copy = strdup(line);
	char *token = strtok(line_copy, " \t\n");

	while (token)
	{
		token_count++;
		token = strtok(NULL, " \t\n");
	}

	free(line_copy);
	command = malloc(sizeof(char *) * (token_count + 1));

	if (!command)
		perror("malloc"), exit(EXIT_FAILURE);

	line_copy = strdup(line);
	token = strtok(line_copy, " \t\n");
	int i = 0;

	while (token)
	{
		command[i] = strdup(token);
		if (!command[i++])
			perror("malloc"), exit(EXIT_FAILURE);
		token = strtok(NULL, " \t\n");
	}

	command[token_count] = NULL;
	free(line_copy);

	return (command);
}
