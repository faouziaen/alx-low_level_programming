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
char **split_string(char *input_str, const char *delimiters)
{
	char **result = NULL;
	char *token;
	int word_count = 0;

	if (input_str == NULL || delimiters == NULL)
		return (NULL);
	/* Count the number of words */
	token = strtok(input_str, delimiters);
	while (token != NULL)
	{
		word_count++;
		token = strtok(NULL, delimiters);
	}

	/* Allocate memory for the result array */
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	/* Split the string and store each word in the result array */
	token = strtok(input_str, delimiters);
	for (int i = 0; i < word_count; i++)
	{
		result[i] = strdup(token);
		token = strtok(NULL, delimiters);
	}
	result[word_count] = NULL; /* Null-terminate the array */
	return (result);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char input_str[] = "This is a test string";
	const char delimiters[] = " ";
	char **words = split_string(input_str, delimiters);

	if (words != NULL)
	{
		int i = 0;

		while (words[i] != NULL)
		{
			printf("Word %d: %s\n", i + 1, words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	return (0);
}
