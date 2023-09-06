#include <stdio.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable.
 *
 * @name: The name of the environment variable.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
    extern char **environ;
    size_t name_len = strlen(name);

    if (name == NULL || environ == NULL)
        return (NULL);

    for (char **env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            return (*env + name_len + 1); // Return the value after the '=' character
        }
    }

    return (NULL); // Environment variable not found
}
