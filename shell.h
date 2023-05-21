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

char *read_input();
void parse_input(char *input, char **args);
int execute_command(char **args);
void handle_cd(char **args);
void handle_exit(char **args);
void error_handler(char **args, char **av, int count);
char *find_executable(char *command);

#endif
