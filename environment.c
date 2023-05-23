#include "shell.h"

/**
 * _getenv - gets address of variable
 * @name: variable whose address is required
 * Return: address from environ
 */

char* _getenv(const char* name)
{
	size_t nameLen = strlen(name);
	int i;

	if (name == NULL || environ == NULL)
		return NULL;
	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(name, environ[i], nameLen) == 0 && environ[i][nameLen] == '=')
		{
			return environ[i] + nameLen + 1; 
		}
	}
	return NULL; 
}
