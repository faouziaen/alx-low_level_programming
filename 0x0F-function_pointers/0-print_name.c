#include "function_pointers.h"

/**
 * print_name - Prints a name using a specified format function
 * @name: Name to be printed
 * @f: Function pointer to the format function
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
        f(name);
}
