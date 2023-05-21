#include "shell.h"

/**
 * handle_cd - handles cd builtin
 * @args: cmd and args
 */

void handle_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
}

/**
 * handle_exit - handles exit builtin
 * @args: cmd and args
 */

void handle_exit(char **args)
{
	if (args[1] != NULL)
	{
		exit(atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}
