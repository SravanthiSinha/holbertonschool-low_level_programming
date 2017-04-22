#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash_table_t
 *
 * @size: size of hash_table_t
 * Return: Returns NULL on failure, or pointer to new hash_table_t
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;

	if (size == 0)
		return (NULL);
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = calloc(size, sizeof(hash_node_t *));
	if (new_table->array == NULL)
		return (NULL);
	return (new_table);
}
