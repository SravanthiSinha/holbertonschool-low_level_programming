#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a list of type struct listint_t.
 * @head: Head node of type struct listint_t.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
