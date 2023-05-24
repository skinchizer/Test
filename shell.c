#include "shell.h"

/**
 * main - entry point
 * @argc: program arguments no.
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *input;
	char *args[MAX_ARGS];
	int command_count = 0;

	while (1)
	{
		input = read_input();
		if (input == NULL)
		{
			free(input);
			break;
		}
		parse_input(input, args);
		if (args[0] != NULL)
		{
			command_count++;
			if (strcmp(args[0], "cd") == 0)
			{
				handle_cd(args);
			}
			else if (strcmp(args[0], "exit") == 0)
			{
				handle_exit(args, input);
			}
			else if (strcmp(args[0], "env") == 0)
			{
				_getenvir(env);
			}
			else
			{
				error_handler(args, argv, command_count, env);
			}
		}
		free(input);
	}
	return (0);
}
