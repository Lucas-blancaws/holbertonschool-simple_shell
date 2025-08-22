#include "shell.h"

/**
 * print_env - prints the current environment
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
 * parse_input - splits a line into arguments
 * @line: input line
 * @args: array of arguments
 * Return: 1 if args found, 0 otherwise
 */

int parse_input(char *line, char **args)
{
	int i;
	char *token;

	i = 0;
	token = strtok(line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
		return (0);

	return (1);
}

/**
 * get_path - get the path
 * Return: path
 */

char *get_path(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
	return (NULL);
}

/**
 * find_command - find a command
 * @cmd: the string
 * Return: the command
 */

char *find_command(char *cmd)
{
	char *path, *copy, *dir;
	char full[256];

	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));

	path = get_path();
	if (path == NULL)
		return (NULL);

	copy = strdup(path);
	if (copy == NULL)
		return (NULL);

	dir = strtok(copy, ":");

	while (dir)
	{
		full[0] = '\0';
		strcpy(full, dir);
		strcat(full, "/");
		strcat(full, cmd);

		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (strdup(full));
		}
		dir = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}

/**
* execute_command - executes a command
* @args: array of arguments
*/

void execute_command(char **args)
{
	 pid_t pid;
	 char *cmd;

	 cmd = find_command(args[0]);

	if (cmd == NULL)
	{
		printf("%s: No such file or directory\n", args[0]);
		return;
	}

	 pid = fork();

	if (pid == 0)
	{
		execve(cmd, args, environ);
		perror("execve");
		exit(2);
	}
	else
	{
		 wait(NULL);
	}
	 free(cmd);
}
