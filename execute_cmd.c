#include "shell.h"

/**
 * execmd - function to execute command
 * @argv: argument count
 *
 * Return: void
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;
	int execute_cmd;

	if (argv)
	{
		command = argv[0];
		actual_cmd = get_location(command);

		execute_cmd = execve(actual_cmd, argv, environ);
		if (execute_cmd == -1)
			perror(argv[0]);

	}
}
