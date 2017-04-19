#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Head node in the linked list.
 *
 * Return: The size of the linked list or node count.
 */
size_t listint_len(const listint_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
