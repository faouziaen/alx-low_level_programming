#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* *
 main - Prints the last digit of a randomly generated number
 * and whether it is greater than 5, less than 6, or 0.
 */
/* This program will assign a random number to the variable n each time it is executed.*/
/* Return always to 0 */
int main(void)
{
	int n;

	int m;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	m = n % 10;
	if (m > 5)
		printf("last digit of %d is %d and is greater than 5\n", n, m);
	if (m == 0)
		printf("last digit of %d is %d and is 0\n", n, m);
	if (m < 6 && m != 0) 
		printf("last digit of %d is %d and is less than 6 and not 0\n", n, m);

	return (0);
}
