#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number from which to get the bit.
 * @index: The index of the bit (starting from 0).
 *
 * Return: The value of the bit at index index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)  /* Ensure index is within valid range */
		return (-1);

	return ((n >> index) & 1);  /* Shift and mask to get the bit value */
}
