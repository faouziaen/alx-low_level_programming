#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

/**
 * main - Super simple shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
    char input[MAX_INPUT];
    pid_t child_pid;
    int status;

    while (1)
    {
        char *command; // Variable to hold the command

        printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        // Tokenize the input to extract the command
        command = strtok(input, " ");

        if (command == NULL)
            continue; // No command provided, prompt for input again

        // Create a child process
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0)
        {
            // Child process
            if (execve(command, &command, NULL) == -1)
            {
                perror("Error:");
                exit(1); // Execve error, exit child process with error status
            }
        }
        else
        {
            // Parent process
            wait(&status);
        }
    }

    return (0);
}
