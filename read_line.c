#include "shell.h"
/**
 * read_line - Lit une ligne entrée par l'utilisateur
 * buffer - adresse du pointeur qui contiendra la ligne lue
 * Return: Nombre de caractères lus, ou -1 en cas d'erreur ou Ctrl+D
 */
int read_line(char **buffer)
{
size_t size = 0;
ssize_t len = getline(buffer, &size, stdin);
return (len);
}
