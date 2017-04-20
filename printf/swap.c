#include "holberton.h"

/**
 * swap - swap characters by reference
 * @a: value to be swapped
 * @b: value to be swapped
 */
void swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}
