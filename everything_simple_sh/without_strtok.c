#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - Splits a string into words.
 * @input_str: The input string to split.
 * @delimiters: The delimiter characters used for splitting.
 *
 * Return: An array of strings containing the words.
 */
char **split_string(const char *input_str, const char *delimiters)
{
    if (input_str == NULL || delimiters == NULL)
        return (NULL);

    char **result = NULL;
    int word_count = 0;
    const char *start = input_str;
    const char *end = input_str;

    // Count the number of words
    while (*end != '\0')
    {
        while (*end != '\0' && strchr(delimiters, *end) != NULL)
            end++;
        if (*end != '\0' && strchr(delimiters, *end) == NULL)
        {
            word_count++;
            while (*end != '\0' && strchr(delimiters, *end) == NULL)
                end++;
        }
    }

    // Allocate memory for the result array
    result = malloc((word_count + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);

    // Split the input string and store each word in the result array
    int i = 0;
    while (*start != '\0')
    {
        while (*start != '\0' && strchr(delimiters, *start) != NULL)
            start++;
        if (*start != '\0' && strchr(delimiters, *start) == NULL)
        {
            const char *word_start = start;
            while (*start != '\0' && strchr(delimiters, *start) == NULL)
                start++;
            const char *word_end = start;
            size_t word_length = word_end - word_start;

            result[i] = malloc((word_length + 1) * sizeof(char));
            if (result[i] == NULL)
            {
                // Handle memory allocation failure
                for (int j = 0; j < i; j++)
                    free(result[j]);
                free(result);
                return (NULL);
            }

            strncpy(result[i], word_start, word_length);
            result[i][word_length] = '\0';
            i++;
        }
    }

    result[word_count] = NULL; // Null-terminate the result array

    return (result);
}

int main(void)
{
    const char input_str[] = "Ceci est un exemple de découpage";
    const char delimiters[] = " ";

    char **words = split_string(input_str, delimiters);

    if (words != NULL)
    {
        int i = 0;
        while (words[i] != NULL)
        {
            printf("Mot %d : %s\n", i + 1, words[i]);
            free(words[i]);
            i++;
        }
        free(words);
    }

    return (0);
}
