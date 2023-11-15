#include "shell.h"
/**
 * _puts - Prints a string to stdout
 * @str: The string to be printed
 */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str++);
	}
}
/**
 * _putchar - Writes a character to standard output
 * @c: The character to be written
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: On success, a pointer to the duplicated string.
 * On failure, exit(EXIT_FAILURE).
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *res = malloc(len);

	if (!res)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (strcpy(res, str));
}
/**
 * _strchr - Locates a character in a string.
 * @str: The string to search in.
 * @c: The character to locate.
 *
 * Return: On success, a pointer to the first occurrence of the character.
 * On failure, returns NULL.
 */
char *_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}

