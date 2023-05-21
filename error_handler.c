#include "shell.h"

/**
 * error_handler - handles errors
 * @args: cmd and args
 * @av: list of program args
 * @count: command counter
 */

void error_handler(char **args, char **av, int count)
{
	char *executable = find_executable(args[0]);

	if (executable != NULL)
	{
		args[0] = executable;
		execute_command(args);
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, args[0]);
	}
}
