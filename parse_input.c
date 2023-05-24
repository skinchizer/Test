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

	token = strtok(input, " \t\n\r");
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		args[i++] = token;
		token = strtok(NULL, " \t\n\r");
	}
	args[i] = NULL;
}
