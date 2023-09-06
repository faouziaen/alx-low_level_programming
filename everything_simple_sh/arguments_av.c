#include <stdio.h>

/**
 * main - Entry point
 * @ac: Number of arguments
 * @av: Array of arguments
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) ac, char *av[])
{
	int i = 0;
	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
