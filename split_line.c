#include "shell.h"
/**
 * split_line - Decoupe une ligne de commande en mots (tokens)
 * @line: ligne tapee par l'utilisateur (ex: "ls -l)
 * Return: tableau de chaines de caracteres (argv), termine©par NULL
 */
char **split_line(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token = strtok(line, " \t\r\n");
while (token != NULL)
{
	tokens[i++] = token;
	if (i >= bufsize)
		tokens = realloc(tokens, (bufsize += 64) * sizeof(char *));
	token = strtok(NULL, " \t\r\n");
}
tokens[i] = NULL;
return (tokens);
}
