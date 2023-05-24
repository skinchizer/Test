#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_ARGS 64

char *read_input(void);
void parse_input(char *input, char **args);
int execute_command(char **args, char **env);
void handle_cd(char **args);
void handle_exit(char **args, char *input);
void error_handler(char **args, char **av, int count, char **env);
char *find_executable(char *command);
void update_pwd_var(void);
char* _getenv(const char* name);
int _atoi(char *s);
void free_tokens(char **tokens);
void _getenvir(char **env);

#endif
