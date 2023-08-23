#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printstr - function to print strings
 * @str: strings to be printed
 *
 * Return: number of strings
 */
int _printstr(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}
/**
 * _getenv - function to get the env
 * @name: path name
 *
 * Return: the env
 */
char *_getenv(char *name)
{
	int i = 0;
	char *value;
	char *en;

	while (environ[i])
	{
		en = strdup(environ[i]);
		value = strtok(en, "=");
		if (_strcmp(value, name) == 0)
			return (strtok(NULL, "="));
		i++;
		free(en);
	}
	return (NULL);
}
