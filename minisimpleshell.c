#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        nread = getline(&line, &len, stdin);
        if (nread == -1) // EOF (Ctrl+D) ou erreur
        {
            printf("\n");
            break; // Quitter le shell
        }

        // Supprimer le saut de ligne final
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (strlen(line) == 0)
            continue; // Ligne vide, on relance la boucle

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            // Processus enfant : exécuter la commande sans argument
            char *argv[] = {line, NULL};

            if (execve(argv[0], argv, environ) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Processus père : attendre que l’enfant termine
            waitpid(pid, &status, 0);
        }
    }

    free(line);
    return 0;
}
