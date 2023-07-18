#include <stdlib.h>
#include <stdio.h>

/**
  * main -Prints alphabets in lowercase
  * description : Prints alphabets in lowercase
  * Return: to 0 always
  */
int main(void)
{
	int a = 65;

	while (a <= 90)
	{
		putchar(a);
		a++;
	}
	putchar('\n');
	return (0);
}
