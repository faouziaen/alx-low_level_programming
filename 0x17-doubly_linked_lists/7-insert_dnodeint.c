#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be added. Index starts at 0.
 * @n: The value to be added to the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int count = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = temp;
		new_node->prev = NULL;
		if (temp)
			temp->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	while (temp)
	{
		if (count == idx - 1)
		{
			new_node->next = temp->next;
			new_node->prev = temp;
			if (temp->next)
				temp->next->prev = new_node;
			temp->next = new_node;
			return (new_node);
		}
		temp = temp->next;
		count++;
	}
	free(new_node);
	return (NULL);
}
