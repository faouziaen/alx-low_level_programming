#include <stdio.h>

/** 
*main - Prints the alphabet in lowercase
*
*Return always to 0
*/
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	putchar('\n');

	return (0);

}
