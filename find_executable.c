#include "shell.h"

/**
 * find_executable - checks if the cmc is exec
 * @command: input command
 * Return: the command if executable
 */

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
	}
	if (path == NULL)
		return (NULL);
	while (dir != NULL)
	{
		char *executable = (char *)malloc(strlen(dir) + strlen(command) + 2);

		strcpy(executable, dir);
		strcat(executable, "/");
		strcat(executable, command);
		if (access(executable, X_OK) == 0)
		{
			free(path_copy);
			return (executable);
		}
		free(executable);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
