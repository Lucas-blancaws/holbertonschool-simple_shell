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
 * execute_command - executes a command or builtin
 * @args: array of arguments
 */

void execute_command(char **args)
{
	pid_t pid;
	int status;

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
	}
}

/**
 * main - entry point of simple shell
 * Return: 0 on success
 */

int main(void)
{
	char line[MAX_INPUT];
	char *args[MAX_ARGS];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(line, sizeof(line), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0)
			break;

		if (parse_input(line, args))
			execute_command(args);
	}

	return (0);
}
