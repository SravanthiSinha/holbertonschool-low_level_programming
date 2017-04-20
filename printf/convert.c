#include "holberton.h"
#include <limits.h>

/**
 * is_number - checks if a character represnts a  number
 * @c: character to be checked
 * @option: values or 1 and 0
 * Description: checks if a character represnts a a number
 * Return: number if character @c is number or -1
 * if its a minus char based on @option .
 */
int is_number(char c, int option)
{
	if (option == 0)
	{
		if (c == 45)
			return (-1);
		else if (c >= 48 && c <= 57)
			return (c - 48);
		return (10);
	}
	else if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * string_to_integer - The function string_to_integer
 * returns the first number contained in a string
 * @s: string to converted.
 * Description: converts an string to integer
 * Return:  returns a number  (int)
 */
int string_to_integer(char *s)
{
	int i, no, r, sign;

	for (i = 0, no = 0, sign = -1; *(s + i) != '\0'; i++)
	{
		r = is_number(*(s + i), 0);
		if (r == -1 && !(is_number(*(s + i - 1), 1)))
			sign *= r;
		else if (r != 10)
		{
			if (no < INT_MIN / 10 || (no == INT_MIN / 10 && no == 9))
				return (0);
			no = (no * 10) - r;
		}
		else if (is_number(*(s + i - 1), 1))
			break;
	}
	if (sign < 0 && no == INT_MIN)
		return (0);
	no *= sign;
	return (no);
}

/**
 * int_str - The function int_str converts a C string to number.
 * @num: num to be converted.
 * @str: stores a converted integer
 * Description: converts an integer to string
 * Return:  returns a C string
 */
char *int_str(int num, char *str)
{
	int i;
	bool isNegative;
	int rem;

	rem = 0;
	i = 0;
	isNegative = false;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0)
	{
		isNegative = true;
		num = -num;
	}
	while (num != 0)
	{
		rem = num % 10;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / 10;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

/**
 * print_oct - Prints the unsigned integer in octal notation.
 * @n: number to be printed.
 * Description: Prints the unsigned integer in octal notation.
 */
void print_oct(unsigned int n)
{
	if (n != 0)
	{
		print_oct(n / 8);
		print_number(n % 8);
	}
}

/**
 * print_bin - Prints the unsigned integer in binary notation.
 * @n: number to be printed.
 * Description: Prints the unsigned integer in binary notation.
 */
void print_bin(unsigned int n)
{
	if (n != 0)
	{
		print_bin(n / 2);
		print_number(n % 2);
	}
}
