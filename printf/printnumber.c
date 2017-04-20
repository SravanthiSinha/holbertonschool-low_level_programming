#include "holberton.h"

/**
 * print_number - Prints the unsigned integer.
 * @n: number to be printed.
 * Description: Prints the unsigned integer.
 */
void print_number(unsigned int n)
{
	if (n > 10)
		print_number(n / 10);
	print_character(n % 10 + 48);
}

/**
 * print_unsigned_binary -  print an un signed integer in binary notation
 * @n: number to be printed.
 * Description:  print an un signed decimal integer in binary notation.
 * Return: Length of the number
 */
int print_unsigned_binary(unsigned int n)
{
	int i;

	i = 0;
	print_bin(n);
	while (n != 0)
	{
		n = n / 2;
		i++;
	}
	return (i);
}

/**
 * print_unsigned_octal -  print an un signed integer in octal notation
 * @n: number to be printed.
 *
 * Description:  print an un signed integer in octal notation.
 * Return: Length of the number
 */
int print_unsigned_octal(unsigned int n)
{
	int i;

	i = 0;
	print_oct(n);
	while (n != 0)
	{
		n = n / 8;
		i++;
	}
	return (i);
}
