#include "shell.h"

/**
 * handle_cd - handles cd builtin
 * @args: cmd and args
 */
void handle_cd(char **args)
{
	char *dir;
	char *oldpwd;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			perror("cd");
			return;
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			perror("cd");
			return;
		}
		write(STDOUT_FILENO, dir, strlen(dir));
		write(STDOUT_FILENO, "\n",1); 
	}
	else
	{
		dir = args[1];
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(dir) != 0)
	{
		perror("cd");
		free(oldpwd);
		return;
	}
	update_pwd_var();
	free(oldpwd);
}
/**
 * handle_exit - handles exit builtin
 * @args: cmd and args
 */

void handle_exit(char **args)
{
	if (args[1] != NULL)
	{
		exit(_atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}
/**
 * update_pwd_var - updates the PWD environment variable
 *
 */

void update_pwd_var(void)
{
	char *pwd = getcwd(NULL, 0);

	if (pwd == NULL)
	{
		perror("getcwd");
		free(pwd);
		return;
	}
	if (setenv("PWD", pwd, 1) != 0)
	{
		perror("setenv");
	}
	free(pwd);
}
/**
 * handle_setenv - handles setenv builtin
 * @args: cmd and args
 */

void handle_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return;
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * handle_unsetenv - handles unsetenv builtin
 * @args: cmd and args
 */

void handle_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		perror("unsetenv");
		return;
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
}
