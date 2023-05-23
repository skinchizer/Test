#include "shell.h"

/**
 * _atoi - convert str to int
 * @str: input string
 * Return: number after conversion
 */
int _atoi(const char *str)
{
	int sign = 1;
	unsigned int result = 0;

	while (*str != '\0')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		else if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
														
		}
		else															{
			break;
		}
		str++;
	}
	return (sign * result);
}
