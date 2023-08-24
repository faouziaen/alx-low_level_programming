#include <stdio.h>

/**
 * myStartupFun - Prints a message before the main function is executed.
 * __attribute__((constructor)) is a GCC-specific feature.
 */
void myStartupFun(void) __attribute__((constructor));

/**
 * myStartupFun - Function that is executed before the main function.
 */
void myStartupFun(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
