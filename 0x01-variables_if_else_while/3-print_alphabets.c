#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, and then in uppercase, followed by a new line
 *
 * Return always to 0
 */
int main(void)
{
	int a = 97;
	int b = 65;

	while (a <= 122)
	{
		putchar(a);
		a++;
	}
	while (b <= 98)
	{
		putchar(b);
		b++;
	}
	putchar('\n');

	return(0);

}

