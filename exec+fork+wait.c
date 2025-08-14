#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

/**
* main - Crée 5 enfants, chacun exécute ls -l /tmp, un par un
*
* Return: 0
*/
int main(void)
{
	pid_t pid;
	int i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		printf("Père: création de l’enfant %d\n", i + 1);

		pid = fork();

		if (pid == -1)
		{
			perror("Erreur fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			// Enfant //
			printf("Enfant %d (PID: %d) : launch ls -l /tmp\n", i + 1, getpid());

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Erreur execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			// Père //
			wait(NULL);
			printf("Père : l’enfant %d est terminé\n\n", i + 1);
		}
	}

	printf("Père : tous les enfants ont terminé.\n");
	return (0);
}
