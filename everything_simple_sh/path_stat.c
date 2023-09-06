#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * _which - Find a file in the PATH.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return (1);
    }

    char *path = getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found.\n");
        return (1);
    }

    char *token = strtok(path, ":");
    while (token != NULL)
    {
        for (int i = 1; i < argc; i++)
        {
            char *file_path = malloc(strlen(token) + strlen("/") + strlen(argv[i]) + 1);
            if (file_path == NULL)
            {
                perror("Error");
                return (1);
            }

            snprintf(file_path, strlen(token) + strlen("/") + strlen(argv[i]) + 1, "%s/%s", token, argv[i]);

            if (access(file_path, F_OK) == 0)
                printf("%s\n", file_path);

            free(file_path);
        }
        token = strtok(NULL, ":");
    }

    return (0);
}
