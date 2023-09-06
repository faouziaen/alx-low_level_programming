#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path_directories - Print each directory in the PATH environment variable.
 */
void print_path_directories(void)
{
    char *path = getenv("PATH");

    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found.\n");
        return;
    }

    char *token = strtok(path, ":");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main(void)
{
    print_path_directories();
    return (0);
}
