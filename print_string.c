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
 * error_msg - Prints custom erro message to standard error
 * @prog: Program name
 * @count: Command count
 * @cmd: Command entered by user
 *
 * Return: Void
 */

void error_msg(char *prog, int count, char *cmd)
{
	_puts(prog);
	_puts(": ");
	_putchar(count);
	_puts(": ");
	_puts(cmd);
	_puts(": not found\n");
}

/**
 * _puts - prints a given string
 * @str: String to be printed
 *
 * Return: Void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
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
	free(en);
	return (NULL);
}
