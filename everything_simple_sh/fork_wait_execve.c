#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Creates child processes to execute "ls -l /tmp".
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    for (int i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0)
        {
            printf("Child process %d executing...\n", getpid());
            execve(argv[0], argv, NULL);
            perror("Error (execve):");
            exit(1); // Terminate the child process if execve fails
        }
        else
        {
            wait(&status);
            printf("Child process %d exited.\n", child_pid);
        }
    }

    return (0);
}
