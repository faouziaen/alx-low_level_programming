#include <stdio.h>

/**
 * add - Add two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The sum of the integers.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtract two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The result of the subtraction (a - b).
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiply two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The product of the integers.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * divide - Divide two integers.
 * @a: First integer (numerator).
 * @b: Second integer (denominator).
 *
 * Return: The result of the division (a / b).
 */
int divide(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Division by zero\n");
		return (-1);
	}
	return (a / b);
}

/**
 * mod - Compute the remainder of the division of two integers.
 * @a: First integer (dividend).
 * @b: Second integer (divisor).
 *
 * Return: The remainder of the division (a % b).
 */
int mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Division by zero\n");
		return (-1);
	}
	return (a % b);
}
