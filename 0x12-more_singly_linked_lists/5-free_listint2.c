#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a list of type struct listint_t.
 * @head: Head node of type struct listint_t.
 */
void free_listint2(listint_t **head)
{
	listint_t *curr;
	listint_t *temp;

	if (head && *head)
	{
		curr = *head;
		while (curr != NULL)
		{
			temp = curr->next;
			free(curr);
			curr = temp;
		}
		*head = NULL;
	}
}
