#include "holberton.h"

/**
 * print_character - writes a character to the screen
 * @c: character to be outputed
 * Description: writes a character to the screen
 * Return: Returns the number of bytes that were written
 */
int print_character(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - writes a string  to the screen
 * @s: string to be outputed
 * Description: writes a string to the screen
 * Return: Returns the number of bytes that were written
 */
int print_string(char *s)
{
	return (write(1, s, str_len(s)));
}

/**
 * print_pointeraddress - writes an address of an pointer
 * @p: pointer of type int*
 * Description: writes a address of an pointer
 * Return: Returns the number of bytes that were written
 */
int print_pointeraddress(int *p)
{
	int divide;
	int count;
	unsigned int *x = (unsigned int *)(&p);

	divide = sizeof(void *) / sizeof(unsigned int);
	count = divide;
	write(1, "0x", 2);
	for (divide--; divide >= 0; divide--)
	{
		print_unsigned_hexdecimal_integer(*(x + divide));
	}
	return (2 + count);
}
