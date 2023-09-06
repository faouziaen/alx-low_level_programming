#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct PathNode - A linked list node to store a directory in the PATH.
 * @directory: A pointer to a directory string.
 * @next: A pointer to the next node in the linked list.
 */
typedef struct PathNode
{
    char *directory;
    struct PathNode *next;
} PathNode;

/**
 * print_path_list - Print each directory in the PATH linked list.
 * @head: A pointer to the head of the linked list.
 */
void print_path_list(PathNode *head)
{
    PathNode *current = head;

    while (current != NULL)
    {
        printf("%s\n", current->directory);
        current = current->next;
    }
}

/**
 * create_path_list - Create a linked list of directories in the PATH.
 * @path: A string containing the PATH environment variable.
 * Return: A pointer to the head of the linked list.
 */
PathNode *create_path_list(const char *path)
{
    PathNode *head = NULL;
    PathNode *tail = NULL;

    char *path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("Memory allocation failed");
        return NULL;
    }

    char *token = strtok(path_copy, ":");

    while (token != NULL)
    {
        PathNode *new_node = malloc(sizeof(PathNode));
        if (new_node == NULL)
        {
            perror("Memory allocation failed");
            free(path_copy);
            return NULL;
        }

        new_node->directory = strdup(token);
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return head;
}

int main(void)
{
    char *path = getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found.\n");
        return 1;
    }

    PathNode *path_list = create_path_list(path);
    if (path_list == NULL)
    {
        return 1;
    }

    print_path_list(path_list);

    // Free memory for the linked list
    while (path_list != NULL)
    {
        PathNode *temp = path_list;
        path_list = path_list->next;
        free(temp->directory);
        free(temp);
    }

    return 0;
}
