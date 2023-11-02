#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	int printed = 0;
	hash_node_t *current = NULL;

	if (ht == NULL)
		return;

	printf("{");
	while (index < ht->size)
	{
		current = ht->array[index];
		while (current != NULL)
		{
			if (printed == 1)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			printed = 1;
			current = current->next;
		}
		index++;
	}
	printf("}\n");
}
