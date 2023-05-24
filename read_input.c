#include "shell.h"

/**
 * read_input - reads input command
 * Return: the command after getting read
 */

char *read_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read;

	if (isatty(fileno(stdin)))
	{
		printf("$ ");
		fflush(stdout);
	}
	read = getline(&input, &input_size, stdin);
	if (read == -1)
	{
		if (input != NULL)
			free(input);
		return (NULL);
	}
	input[strcspn(input, "\n")] = '\0';
	return (input);
}
