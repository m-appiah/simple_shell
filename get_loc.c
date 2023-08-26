#include "shell.h"

/**
 * search_directory - function to search for directory
 * @directory: directory to be searched
 * @command: command to search for the directory
 *
 * Return: directory
 */
char *search_directory(char *directory, char *command)
{
	char *file_path = NULL;
	int command_length = _strlen(command);
	struct stat buffer;

	file_path = malloc(command_length + _strlen(directory) + 2);
	if (file_path == NULL)
	{
		perror("Memory allocation fail");
		free(file_path);
		exit(1);
	}

	_strcpy(file_path, directory);
	_strcat(file_path, "/");
	_strcat(file_path, command);

	if (stat(file_path, &buffer) == 0)
	{
		return (file_path);
	}
	else
	{
		free(file_path);
		return (NULL);
	}
}
/**
 * get_location - function to get the PATH
 * @command: command to get the path
 *
 * Return: the path
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	struct stat buffer;

	path = _getenv("PATH");

	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (path == NULL)
		free(path);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		file_path = search_directory(path_token, command);
		if (file_path != NULL)
		{
			free(path_copy);
			return (file_path);
		}
		path_token = strtok(NULL, ":");
	}
	free(path_copy);

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
}
