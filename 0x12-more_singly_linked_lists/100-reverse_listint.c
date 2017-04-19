#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint_tint - *reverses a listint_t linked list
 * @head: Head node of type struct listint_t.
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *curr;
	listint_t *prev;

	if (!*head)
		return (NULL);
	curr = *head;
	while (curr->next)
	{
		prev = curr->next;
		curr->next = prev->next;
		prev->next = *head;
		*head = prev;
	}
	return (*head);
}
