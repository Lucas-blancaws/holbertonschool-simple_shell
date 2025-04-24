#include "shell.h"
/**
 * prompt- affiche prompt dans le terminal
 * Return: $
 */
void prompt(void)
{
write(STDOUT_FILENO, "$ ", 2);
}
