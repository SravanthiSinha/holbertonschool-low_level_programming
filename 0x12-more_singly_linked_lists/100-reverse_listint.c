#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint_tint - *reverses a listint_t linked list
 * @head: Head node of type struct listint_t.
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint_tint(listint_t **head)
{
	listint_t *prev;
	listint_t *nxt;

	prev = NULL;
	while (*head != NULL)
	{
		nxt = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = nxt;
	}
	*head = prev;
	return (*head);
}
