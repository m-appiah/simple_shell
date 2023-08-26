#include "shell.h"

/**
 * execmd - function to execute command
 * @argv: argument count
 * @prog: program name
 *
 * Return: void
 */
void execmd(char **argv, char **prog)
{
	char *command = NULL, *actual_cmd = NULL, cmd_count;
	int execute_cmd, count = 0;

	if (argv)
	{
		command = argv[0];
		actual_cmd = get_location(command);

		if (actual_cmd == NULL)
		{
			cmd_count = (count + '0');
			error_msg(prog[0], cmd_count, argv[0]);
			/*perror(argv[0]);*/
			free(actual_cmd);
			errno = 127;
		}

		execute_cmd = execve(actual_cmd, argv, environ);
		if (execute_cmd == -1)
		{
			free(actual_cmd);
			perror(argv[0]);
			exit(2);
		}
	}
}
