#include "shell.h"

/**
 * main - program entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int num_tokens, i;
	char *input;
	char **argv_tokens;

	for (;;)
	{
		_prompt();
		input = read_input();

		if (input == NULL)
		{
			break;
		}

		if (_strlen(input) == _strspn(input, " \t\n"))
		{
			free(input);
			continue;
		}

		if (input[_strlen(input) - 1] == '\n')
			input[_strlen(input) - 1] = '\0';

		argv_tokens = tokenize_input(input, &num_tokens);
		execute_command(argv_tokens);

		for (i = 0; argv_tokens[i] != NULL; i++)
		{
			free(argv_tokens[i]);
		}
		free(argv_tokens);
		free(input);
	}
	return (0);
}
