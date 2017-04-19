#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Head node of type struct listint_t.
 * @n: Value to be store into the node.
 *
 * Return: New created node: listint_t of type struct.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node;
	listint_t *temp;

	node = malloc(sizeof(listint_t));

	node->n = n;
	node->next = NULL;

	if (node == NULL)
		return (NULL);
	else if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
	return (temp);
}
