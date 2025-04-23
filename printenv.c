#include <stdio.h>

extern char **environ;

/**
 * main - prints all environment variables using environ
 *
 * Return: 0 always
 */
int main(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
