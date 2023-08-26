#include "shell.h"

/**
 * builtins - function to handle builtins
 * @argv_tokens: tokenized strings
 *
 * Return: exec_count
 */
int builtins(char **argv_tokens)
{
	int exec_count = 0, i = 0;

	if (_strcmp(argv_tokens[0], "exit") == 0)
	{
		free(argv_tokens);
		exit(2);
	}
	else if (strcmp(argv_tokens[0], "cd") == 0)
	{
		if (argv_tokens[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(argv_tokens[1]);
		return (1);
	}
	else if (_strcmp(argv_tokens[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			write(1, environ[i], strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
		exec_count = 1;
	}
	return (exec_count);
}
