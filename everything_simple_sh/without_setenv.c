#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - Change or add an environment variable.
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 * @overwrite: Flag to indicate whether to overwrite if the variable already exists.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        return -1; // Invalid variable name.
    }

    char *env_var = getenv(name);

    if (env_var != NULL && !overwrite) {
        return 0; // Variable already exists, and we are not allowed to overwrite.
    }

    // Concatenate name and value to create the environment variable string.
    size_t len = strlen(name) + strlen(value) + 2; // +2 for '=' and '\0'.
    char *new_env_var = (char *)malloc(len);

    if (new_env_var == NULL) {
        return -1; // Memory allocation failed.
    }

    snprintf(new_env_var, len, "%s=%s", name, value);

    if (putenv(new_env_var) != 0) {
        free(new_env_var);
        return -1; // Failed to set the environment variable.
    }

    return 0;
}

int main(void)
{
    // Example usage:
    printf("Before setting MY_VAR: %s\n", getenv("MY_VAR"));

    if (_setenv("MY_VAR", "new_value", 1) == 0) {
        printf("After setting MY_VAR: %s\n", getenv("MY_VAR"));
    } else {
        printf("Failed to set MY_VAR\n");
    }

    return 0;
}
