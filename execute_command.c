#include "shell.h"
/**
 * execute_command - Execute une commande externe
 * @argv: tableau contenant commande et arguments
 * @env: tableau des variables d'environnement
 * Return: 0 si succes, ou un code d'erreur
 */
int execute_command(char **argv, char **env)
{
char *cmd_path;
struct stat st;
if (strchr(argv[0], '/'))
{
	if (stat(argv[0], &st) != 0)
	{
		perror(argv[0]);
		return (-1);
	}
	cmd_path = argv[0];
}
	else
	{
		cmd_path = find_in_path(argv[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: command not found\n", argv[0]);
			return (-1);
		}
	}
pid_t pid = fork();
if (pid == 0)
{
	execve(cmd_path, argv, env);
	perror("execve");
	exit(EXIT_FAILURE);
}
else if (pid > 0)
{
	int status;
	waitpid(pid, &status, 0);
}
else
	perror("fork");

return (0);
}
