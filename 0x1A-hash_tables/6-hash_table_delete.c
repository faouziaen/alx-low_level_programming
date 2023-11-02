#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to be deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *current = NULL, *temp = NULL;

	if (ht == NULL)
		return;
	while (index < ht->size)
	{
		current = ht->array[index];
		while (current != NULL)
		{
			temp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp;
		}
		index++;
	}
	free(ht->array);
	free(ht);
}
