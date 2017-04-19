#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at an index in a linked list.
 * @head: Head node of type struct listint_t.
 * @index: Index to be deleted.
 *
 * Return: 1 if it success, -1 if Error.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr;
	listint_t *temp;
	unsigned int i;

	curr = *head;

	for (i = 0; curr != NULL; i++)
	{
		if (index == 0)
		{
			*head = curr->next;
			free(curr);
			return (1);
		}
		else if (i == index - 1)
		{
			temp = curr->next;
			curr->next = temp->next;
			free(temp);
			return (1);
		}
		curr = curr->next;
	}
	return (-1);
}
