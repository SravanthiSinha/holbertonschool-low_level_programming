#ifndef LISTS
#define LISTS

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/*
 * print_listint - Displays the values of each node and
 * returns the number of elements in a linked listint_t list.
 */
size_t print_listint(const listint_t *h);

/* listint_len - Returns the number of elements. */
size_t listint_len(const listint_t *h);

/* add_nodeint - Adds a new node at the beginning of a listint_t list. */
listint_t *add_nodeint(listint_t **head, const int n);

/* add_nodeint_end - Adds a new node at the end of a listint_t list. */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* free_listint - Frees a list of type struct listint_t. */
void free_listint(listint_t *head);

/* free_listint2 - Frees a list of type struct listint_t */
void free_listint2(listint_t **head);

/* pop_listint - Deletes the head node of a listint_t linked list. */
int pop_listint(listint_t **head);

/* get_nodeint_at_index - Returns the nth node of a listint_t linked list. */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* sum_listint - Returns the sum of all the data (n) of a linked list. */
int sum_listint(listint_t *head);

/* insert_nodeint_at_index - Inserts a new node at a given Index. */
listint_t *insert_nodeint_at_index(listint_t **, unsigned int, int);

/* delete_nodeint_at_index - Deletes a node at an index in a linked list. */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

#endif /* LISTS */
