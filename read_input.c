#include "shell.h"

/**
 * read_input - reads input command
 * Return: the command after getting read
 */

char *read_input()
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read = getline(&input, &input_size, stdin);
	if (read == -1)
	{
		free(input);
		return NULL;
	}
	input[strcspn(input, "\n")] = '\0';
	return (input);
}
