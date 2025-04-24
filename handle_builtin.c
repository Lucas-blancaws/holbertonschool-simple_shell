#include "shell.h"
/**
 * handle_builtin - Gere les commandes internes ("exit", "env")
 * @argv: tableau de chaines contenant la commande entree
 * Return: 1 si une commande built-in a ete geree, 0 sinon
 */
extern char **environ;
int handle_builtin(char **argv)
{
if (!argv[0])
	return (0);

if (strcmp(argv[0], "exit") == 0)
	exit(0);

if (strcmp(argv[0], "env") == 0)
{
	for (int i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return (1);
}
return (0);
}
