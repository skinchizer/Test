#include "shell.h"

/**
 * main - entry point
 * @argc: program arguments no.
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *input;
	char *args[MAX_ARGS];
	int command_count = 0;

	while (1)
	{
		printf("($) ");
		input = read_input();
		if (input == NULL)
		{
			printf("\n");
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
				handle_exit(args);
			}
			else if (strcmp(args[0], "setenv") == 0)
			{
				handle_setenv(args);
			}
			else if (strcmp(args[0], "unsetenv") == 0)
			{
				handle_unsetenv(args);
			}
			else
			{
				error_handler(args, argv, command_count);
			}
		}
	}
	return (0);
}
