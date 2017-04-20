#include "holberton.h"
#include <stdarg.h>

/**
 * print_o - Choose the format to be printed based on the specifier
 * @ap: its mine damnit
 * @p: the total number of characters written.
 * @i: the postion of the character to check the specifier
 * @format: This is the string that contains the text to be written to stdout.
 * It can optionally contain embedded format tags that are replaced by the
 * values specified in subsequent additional arguments and formatted as
 * requested.
 * Description: Choose the format to be printed based on the specifier
 */
void print_o(va_list ap, int *p, int *i, const char *format)
{
	if (format[*i + 1] == 'i')
		*p += print_signed_decimal_int(va_arg(ap, signed int));
	else if (format[*i + 1] == 'd')
		*p += print_signed_decimal_int(va_arg(ap, signed int));
	else if (format[*i + 1] == 'u')
		*p += print_unsigned_decimal_int(va_arg(ap, unsigned int));
	else if (format[*i + 1] == 'o')
		*p += print_unsigned_octal(va_arg(ap, unsigned int));
	else if (format[*i + 1] == 'x')
		*p += print_unsigned_hexdecimal_integer(va_arg(ap, unsigned int));
	else if (format[*i + 1] == 'X')
		*p += print_unsigned_hexdecimal_integer_U(va_arg(ap, unsigned int));
	else if (format[*i + 1] == 'c')
		*p += print_character((char)va_arg(ap, int));
	else if (format[*i + 1] == 's')
		*p += print_string(va_arg(ap, char *));
	else if (format[*i + 1] == 'p')
		*p += print_pointeraddress(va_arg(ap, int *));
	else if (format[*i + 1] == 'b')
		*p += print_unsigned_binary(va_arg(ap, unsigned int));
	else if (format[*i + 1] == '%')
		*p += print_character('%');
	else
	{
		print_character('%');
		print_character(format[*i + 1]);
		*p += 2;
	}
}

/**
 * _printf - Recoded the function printf of the C library
 * @format: This is the string that contains the text to be written to stdout.
 * It can optionally contain embedded format tags that are replaced by the
 * values specified in subsequent additional arguments and formatted as
 * requested.
 * Description: sends formatted output to stdout.
 * Return:If successful, the total number of characters written is returned.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int *i, *p;
	int len;
	int a, b;

	a = 0, b = 0;
	va_start(ap, format);
	i = &a;
	p = &b;
	len = str_len(format);
	while (format[*i])
	{
		if (format[*i] == '%' && *i < len)
		{
			print_o(ap, p, i, format);
			(*i)++;
		}
		else
		{
			(*p)++;
			print_character(format[*i]);
		}
		(*i)++;
	}
	va_end(ap);
	return (*p);
}
