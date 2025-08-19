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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		if (getline(&line, &len, stdin) == -1)
			break;

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
			execute_command(args);
	}

	free(line);
	return (0);
}
