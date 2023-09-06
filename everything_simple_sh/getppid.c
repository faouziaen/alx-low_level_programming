#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	pid_t parent_pid;
	parent_pid = getppid();
	printf("Parent PID: %d\n", (int)parent_pid);
	return (0);
}
