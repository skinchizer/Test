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

void handle_exit(char **args, char *input)
{
	if (args[1] != NULL)
	{
		free(input);
		exit(atoi(args[1]));
	}
	else
	{
		free(input);
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
 * free_tokens - frees tokens
 * @tokens: array of tokens
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
/**
 *  *_getenvir - gets the env variable.
 *   *@env: env variable
 *    *Return: 0
 *     */

void _getenvir(char **env)
{
	size_t env_v = 0;

	while (env[env_v])
	{
		write(STDOUT_FILENO, env[env_v], strlen(env[env_v]));
		write(STDOUT_FILENO, "\n", 1);
		env_v++;
	}
}
