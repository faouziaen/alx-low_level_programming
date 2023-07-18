#include "main.h"

/**
 * _islower- Write a function that checks for lowercase character
 *Return: Returns: 1 if c is lowercase
 * c: is a parameter of the function
 * Returns: 0 otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
