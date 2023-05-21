#include "shell.h"

/**
 * parse_input - splits command into args
 * @input: the command
 * @args: command and its args
 */

void parse_input(char *input, char **args)
{
	char *token;
	int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
