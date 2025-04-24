#include "shell.h"
/**
 * find_in_path - Recherche le chemin absolu d'une commande dans le PATH
 * @cmd: nom de la commande (ex: "ls") 
 * Return: chaîne contenant le chemin complet ou NULL si non trouve
 */
char *find_in_path(const char *cmd)
{
char *path = getenv("PATH");
char *copy = strdup(path);
char *dir = strtok(copy, ":");
static char full[1024];
struct stat st;
while (dir)
{
snprintf(full, sizeof(full), "%s/%s", dir, cmd);
	if (stat(full, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		free(copy);
		return full;
	}
	dir = strtok(NULL, ":");
}
free(copy);
return NULL;
}
