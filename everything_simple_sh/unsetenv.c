#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ; /* Access the global environment variable. */

/**
 * _unsetenv - Delete an environment variable.
 * @name: Name of the environment variable to delete.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        return (-1); /* Invalid variable name. */
    }

    /* Calculate the length of the environment variable name. */
    size_t name_len = strlen(name);

    /* Iterate through the environment variables. */
    for (int i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            /* Found the environment variable to delete. */
            /* Shift all subsequent environment variables up. */
            for (int j = i; environ[j] != NULL; j++)
            {
                environ[j] = environ[j + 1];
            }
            return (0); /* Successfully deleted the variable. */
        }
    }

    return (-1); /* Variable not found, which is considered a failure. */
}

int main(void)
{
    /* Example usage: */
    printf("Before unsetting MY_VAR: %s\n", getenv("MY_VAR"));

    if (_unsetenv("MY_VAR") == 0)
    {
        printf("After unsetting MY_VAR: %s\n", getenv("MY_VAR"));
    }
    else
    {
        printf("Failed to unset MY_VAR\n");
    }

    return (0);
}
