#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void prompt(void);
int read_line(char **buffer);
char **split_line(char *line);
char *find_in_path(const char *cmd);
int execute_command(char **argv, char **env);
int handle_builtin(char **argv);

#endif
