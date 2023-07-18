#include <stdio.h>

/**
 * main - This programm prints alphabets
 * Description: Print lowercase alphabets in reverse
 * Return: always to zero (success)
 */
int main(void)
{
	int a = 122;

	while (a >= 97)
	{
		putchar(a);
		a--;
	}
	putchar('\n');
	return (0);
}
