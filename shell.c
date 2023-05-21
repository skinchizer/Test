#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

char *read_input();
void parse_input(char *input, char **args);
int execute_command(char **args);
void handle_cd(char **args);
void handle_exit(char **args);
void run_advanced_task(char **args, char **av, int count);
char *find_executable(char *command);

int main(int argc, char **argv) {
    char *input;
    char *args[MAX_ARGS];
    int command_count = 0;

    (void)argc;
    while (1) {
        printf("($) ");
	input = read_input();
        if (input == NULL) {
            printf("\n");
            break;
        }
        parse_input(input, args);

        if (args[0] != NULL) {
		command_count++;
            if (strcmp(args[0], "cd") == 0) {
                handle_cd(args);
            } else if (strcmp(args[0], "exit") == 0) {
                handle_exit(args);
            }else {
                run_advanced_task(args, argv, command_count);
            }
        }
    }

    return 0;
}

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


void parse_input(char *input, char **args) {
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int execute_command(char **args) {
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        execve(args[0], args, environ);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking");
    }else{
	    waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}

void handle_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: expected argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
}

void handle_exit(char **args) {
    if (args[1] != NULL) {
        exit(atoi(args[1]));
    } else {
        exit(0);
    }
}

void run_advanced_task(char **args, char **av, int count) {
	char *executable = find_executable(args[0]);

        if (executable != NULL) {
            args[0] = executable;
            execute_command(args);
        } else {
            fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, args[0]);
        }
}

char *find_executable(char *command) {
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
    if (command[0] == '/') {
	    if (access(command, X_OK) == 0)
		    return command;
	    return NULL;
    }

    if (path == NULL) {
        return NULL;
    }

    while (dir != NULL) {
        char *executable = (char *)malloc(strlen(dir) + strlen(command) + 2);
        sprintf(executable, "%s/%s", dir, command);
        if (access(executable, X_OK) == 0) {
            free(path_copy);
            return executable;
        }
        free(executable);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
