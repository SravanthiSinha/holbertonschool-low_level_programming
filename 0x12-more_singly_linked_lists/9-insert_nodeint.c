#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given Index.
 * @head: Head node of type struct listint_t.
 * @index: Index for insertetion of new node.
 * @n: Number to be inserted into new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *curr;
	listint_t *temp;
	unsigned int i;

	curr = *head;
	temp = malloc(sizeof(listint_t));
	if (*head == NULL)
	{
		temp->n = n;
		temp->next = NULL;
		*head = temp;
		return (temp);
	}
	for (i = 0; curr != NULL; i++)
	{
		if (index == 0)
		{
			temp->n = n;
			temp->next = *head;
			*head = temp;
			return (temp);
		}
		else if (i == index - 1)
		{
			temp->n = n;
			temp->next = curr->next;
			curr->next = temp;
			return (temp);
		}
		curr = curr->next;
	}
	return (NULL);
}
