#include "shell.h"

/**
 * _prompt - function to display prompt
 * Return: void
 */
void _prompt(void)
{
	const char *prompt = "cisfun$:) ";

	if (isatty(0) == 1)
		write(STDOUT_FILENO, prompt, 10);
}
/**
 * read_input - function to read user input
 * Return: input
 */
char *read_input()
{
	char *input = NULL;
	size_t n = 0;
	ssize_t read_chars;
	int i = 0;

	read_chars = getline(&input, &n, stdin);
	if (read_chars == -1)
	{
		free(input);
		/*_putchar('\n');*/
		exit(0);
	}
	while (input[i])
	{
		if (i > 0 && input[i] == '#' && input[i - 1] != ' ')
			break;
		if (input[i] == '#')
		{
			input[i] = '\0';
			break;
		}
		i++;
	}
	return (input);
}
/**
 * tokenize_input - function to tokenize user input
 * @input: user input
 * @num_tokens: number of tokens after tokenizing input
 *
 * Return: argv of tokens
 */
char **tokenize_input(char *input, int *num_tokens)
{
	char *input_copy, *delim = " \t\n", *token;
	int i;
	char **argv;

	input_copy = _strdup(input);
	if (input_copy == NULL)
	{

		perror("Error: ");
		exit(1);
	}
	token = strtok(input, delim);
	*num_tokens = 0;

	while (token != NULL)
	{
		(*num_tokens)++;
		token = strtok(NULL, delim);
	}
	(*num_tokens)++;

	argv = malloc(sizeof(char *) * (*num_tokens));
	if (argv == NULL)
	{
		perror("Error:");
		free(argv);
		exit(1);
	}
	token = strtok(input_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(input_copy);
	return (argv);
}

/**
 * execute_command - function to execute command
 * @argv: command argument
 * @prog: program name
 *
 * Return: void
 */
void execute_command(char **argv, char **prog)
{
	pid_t pid;
	int status;

	/**
	 * if (_strcmp(argv[0], "#") == 0)
	{
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		exit(0);
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		exit(e);
	}
	*/
	pid = fork();
	if (pid < 0)
	{
		perror(argv[0]);
		exit(2);
	}
	else if (pid == 0)
	{
		execmd(argv, prog);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
}
