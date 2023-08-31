#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *end_check = (char *)&i;

	return (*end_check == 1);
}
