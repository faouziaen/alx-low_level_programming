#include "main.h"

/**
 * _strstr - Entry point
 * @haystack: input
 * @needle: input
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *b = haystack;
		char *p = needle;

		while (*b == *p && *p != '\0')
		{
			b++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
