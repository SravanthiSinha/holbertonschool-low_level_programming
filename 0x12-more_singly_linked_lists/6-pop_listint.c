#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Head node of type struct listint_t.
 *
 * Return: Head node's data (int).
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int no;

	if (head && *head)
	{
		if ((*head)->next != NULL)
			tmp = (*head)->next;
		no = (*head)->n;
		free(*head);
		*head = tmp;
	}
	else
		return (0);
	return (no);
}
