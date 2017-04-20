#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int bool;
#define true 1
#define false 0

void print_oct(unsigned int n);
void print_bin(unsigned int n);
char *int_str(int num, char *str);
int print_signed_decimal_int(signed int);
int print_unsigned_decimal_int(unsigned int);
int print_unsigned_octal(unsigned int);
int print_unsigned_binary(unsigned int);
int print_unsigned_hexdecimal_integer(unsigned int);
int print_unsigned_hexdecimal_integer_U(unsigned int);
int print_character(char);
int print_string(char *);
int print_pointeraddress(int *);
void print_number(unsigned int);
void swap(char *a, char *b);
int is_number(char c, int option);
int string_to_integer(char *s);
int _printf(const char *format, ...);
void print_o(va_list ap, int *p, int *i, const char *format);
char *string_concat(char *dest, char *src);
int str_len(const char *s);
int str_ncomp(char *s1, char *s2, int k);
void reverse(char str[], int length);
char *string_dup(char *str);

#endif
