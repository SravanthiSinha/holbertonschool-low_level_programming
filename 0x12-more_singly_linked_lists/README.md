# Singly Linked List Project

* Data structure for this project:

```c
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
```

## Functions

```c
/*
 * print_listint - Displays the values of each node and
 * returns the number of elements in a linked listint_t list.
 */
size_t print_listint(const listint_t *h);
```

```c
/* listint_len - Returns the number of elements. */
size_t listint_len(const listint_t *h);
```

```c
/* add_nodeint - Adds a new node at the beginning of a listint_t list. */
listint_t *add_nodeint(listint_t **head, const int n);
```

```c
/* add_nodeint_end -Adds a new node at the end of a listint_t list. */
listint_t *add_nodeint_end(listint_t **head, const int n);
```

```c
/* free_listint - Free a list of type struct listint_t. */
void free_listint(listint_t *head);
```

```c
/* free_listint2 - Frees a list of type struct listint_t, set node to NULL. */
void free_listint2(listint_t **head);
```

```c
/* pop_listint - deletes the head node of a listint_t linked list. */
int pop_listint(listint_t **head);
```

```c
/* get_nodeint_at_index - Returns the nth node of a listint_t linked list. */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
```

```c
/* sum_listint - Returns the sum of all the data (n) of a linked list. */
int sum_listint(listint_t *head);
```

```c
/* insert_nodeint_at_index - Inserts a new node at a given Index. */
listint_t *insert_nodeint_at_index(listint_t **, unsigned int, int);
```

```c
/* delete_nodeint_at_index - Deletes a node at an index in a linked list. */
int delete_nodeint_at_index(listint_t **head, unsigned int index);
```

```c
/*reverses a listint_t linked list*/
listint_t *reverse_listint(listint_t **head);
```
