#include "shell.h"
/**
 * main - execute a shell
 * Return: 0
 */
int main(void)
{
char *line = NULL;
extern char **environ;
char **args;
size_t len = 0;

    while (1)
    {
        prompt();
        if (read_line(&line) == -1)
            break;
        args = split_line(line);
        if (!handle_builtin(args))
            execute_command(args, environ);
        free(args);
    }
    free(line);
    return (0);
}
