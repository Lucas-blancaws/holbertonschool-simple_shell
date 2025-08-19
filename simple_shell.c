#include "shell.h"

/**
 * main - entry point of simple shell
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS];
	char *cmd;

	while (1)
	{
		printf("#cisfun$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}
		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		if (strcmp(line, "env") == 0)
		{
			print_env();
			continue;
		}
		if (parse_input(line, args))
		{
			cmd = find_command(args[0]);
			if (!cmd)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				continue;
			}
			execute_command(args, cmd);
		}
	}

	free(line);
	return (0);
}
