#include "shell.h"

/**
 * execute_command - executes the command
 * @args: command and arguments
 * Return: returns 1 on success
 */

int execute_command(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("exceve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error forking");
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
