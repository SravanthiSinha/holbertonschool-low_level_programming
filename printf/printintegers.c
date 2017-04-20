#include "holberton.h"

/**
 * print_signed_decimal_int -  print an signed decimal integer
 * @n: number to be printed.
 * Description: print an signed decimal integer
 * Return: Length of the number
 */
int print_signed_decimal_int(signed int n)
{
	char s[100];

	if (n < 0)
	{
		n = n * -1;
		print_character('-');
	}
	print_number(n);
	int_str(n, s);
	return (str_len(s));
}

/**
 * print_unsigned_decimal_int -  print an un signed decimal integer
 * @n: number to be printed.
 * Description:  print an un signed decimal integer
 * Return: Length of the number
 */
int print_unsigned_decimal_int(unsigned int n)
{
	char s[100];

	print_number(n);
	int_str(n, s);
	return (str_len(s));
}

/**
 * print_unsigned_hexdecimal_integer -  print an un signed integer
 *					 in hexadecimal notation
 * @n: number to be printed.
 * Description:  print an un signed integer in hexadecimal notation
 * Return: Length of the number
 */
int print_unsigned_hexdecimal_integer(unsigned int n)
{
	int r, i, k;
	int no;
	char c[] = "0123456789abcdef";
	char s[] = "00000000";

	i = 7;
	k = 0;
	no = 0;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		k++;
		i++;
	}
	return (k);
}

/**
 * print_unsigned_hexdecimal_integer_U -  print an un signed integer
 *					 in hexadecimal notation
 * @n: number to be printed.
 *
 * Description:  print an un signed integer in hexadecimal notation
 * Return: Length of the number
 */
int print_unsigned_hexdecimal_integer_U(unsigned int n)
{
	int r, i, k;
	int no;
	char c[] = "0123456789ABCDEF";
	char s[] = "00000000";

	i = 7;
	k = 0;
	while (n > 16)
	{
		r = n % 16;
		s[i] = (c[r]);
		i--;
		n = n / 16;
	}
	s[i] = c[n];
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != '0')
			no++;
		if (no)
			print_character(*(s + i));
		k++;
		i++;
	}
	return (k);
}
