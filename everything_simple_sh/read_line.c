#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	(void)ac;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n') // Remove trailing newline
			line[read - 1] = '\0';
		printf("%s\n", line);
		printf("$ ");
	}
	free(line);
	return (0);
}
