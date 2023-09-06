#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - Print the addresses of env and environ.
 *
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 * @env: Array of environment variable strings.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    printf("Address of 'env' (third parameter of main): %p\n", (void *)env);
    printf("Address of 'environ' (global variable): %p\n", (void *)environ);

    return (0);
}
