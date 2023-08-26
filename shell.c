#include "shell.h"

/**
 * main - program entry point
 * @argc: argument counter
 * @prog: program name
 *
 * Return: 0 (success)
 */
int main(int argc, char **prog)
{
	int num_tokens, i, count;
	char *input;
	char **argv_tokens;

	(void)argc;

	for (;;)
	{
		count++;
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

		if (builtins(argv_tokens) == 1)
			continue;
		execute_command(argv_tokens, prog);

		for (i = 0; argv_tokens[i] != NULL; i++)
		{
			free(argv_tokens[i]);
		}
		free(argv_tokens);
		free(input);
	}
	return (0);
}
