#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print - Print a message and exit with success status.
 * @format: A format string (unused in this example).
 *
 * Return: This function does not return a value.
 */
int print(const char *format, ...)
{
	write(1, "9 8 10 24 75 - 9\n",17);
	write(1, "Congratulations, you win the Jackpot\n", 38);
	exit(EXIT_SUCCESS);
}
