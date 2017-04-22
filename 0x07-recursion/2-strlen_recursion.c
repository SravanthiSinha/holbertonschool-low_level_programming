#include "holberton.h"

/**
 * _strlen_recursion - get length of string, recursively
 *
 *
 * @s: string to get length
 * Return: length of string as an int
 */

int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (_strlen_recursion(++s) + 1);
	return (0);
}
