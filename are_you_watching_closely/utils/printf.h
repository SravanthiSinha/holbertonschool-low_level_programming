#include <unistd.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

char* int_str(int num, char* str);
int print_signed_decimal_int(signed int);
int print_unsigned_decimal_int(unsigned int);
int print_unsigned_octal(unsigned int);
int print_unsigned_hexdecimal_integer(unsigned int);
int print_unsigned_hexdecimal_integer_U(unsigned int);
int print_character(char);
int print_string(char *);
int print_pointeraddress(int *);
void print_number(unsigned int);
void swap(char *a,char *b);
int is_number(char c, int option);
int string_to_integer(char *s);
