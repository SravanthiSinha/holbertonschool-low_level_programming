#include "holberton.h"

/**
 * _puts_recursion - Recursive function to print entire string using puts
 *
 *
 * @s: string to print
 * Return: void
 */

void _puts_recursion(char *s)
{
	if (s[0] != '\0')
	{
		_putchar(s[0]);
		_puts_recursion(s + 1);
	}
	else
	{
		_putchar(10);
	}
}
