#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void execute_command(char **args, char *cmd);
void print_env(void);
int parse_input(char *line, char **args);
char *find_command(char *cmd);
char *get_path(void);

#endif
