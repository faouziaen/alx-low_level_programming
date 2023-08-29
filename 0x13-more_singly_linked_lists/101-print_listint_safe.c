#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}
		count++;
	}
	while (head != slow)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
		slow = slow->next;
	}
	if (slow)
	{
		printf("-> [%p] %d\n", (void *)slow, slow->n);
	}
	return (count);
}
