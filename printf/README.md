# C - printf

## Functions

```c
/* is_number - checks if a character represents a a number */
 int is_number(char c, int option);
```

```c
/* string_to_integer - The function string_to_integer */
int string_to_integer(char *s);
```

```c
/* int_str - The function int_str converts a C string to number.*/
char *int_str(int num, char *str);
```

```c
/* print_oct - Prints the unsigned integer in octal notation.*/
void print_oct(unsigned int n);
```

```c
/* print_bin - Prints the unsigned integer in binary notation.*/
void print_bin(unsigned int n);
```

```c
/* print_o - Choose the format to be printed based on the specifier*/
void print_o(va_list ap, int *p, int *i, const char *format);
```

```c
/* _printf - Recoded the function printf of the C library*/
 int _printf(const char *format, ...);
```

```c
 /* print_signed_decimal_int -  print an signed decimal integer*/
 int print_signed_decimal_int(signed int);
```

```c
/* print_unsigned_decimal_int -  print an un signed decimal integer*/
int print_unsigned_decimal_int(unsigned int);
```

```c
/* print_unsigned_hexdecimal_integer -  print an un signed integer
 *					 in hexadecimal notation*/
  int print_unsigned_hexdecimal_integer(unsigned int);
```

```c
/* print_unsigned_hexdecimal_integer_U -  print an un signed integer
 *					 in hexadecimal notation */
 int print_unsigned_hexdecimal_integer_U(unsigned int);
 ```

```c
/* print_character - writes a character to the screen */
int print_character(char);
```

```c
/* print_string - writes a string  to the screen*/
int print_string(char *);
```

```c
/*print_pointeraddress - writes an address of an pointer */
int print_pointeraddress(int *);
```

```c
/* print_unsigned_binary -  print an un signed integer in binary notation*/
int print_unsigned_binary(unsigned int);
```

```c
/* print_unsigned_octal -  print an un signed integer in octal notation */
int print_unsigned_octal(unsigned int);
```

```c
/* print_number - Prints the unsigned integer.*/
void print_number(unsigned int);
```

```c
/* swap - swap characters by reference*/
void swap(char *a, char *b);
```

```c
/* string_concat - concatinates the given 2 strings*/
char *string_concat(char *dest, char *src);
```

```c
/* str_len - A function which returns the length of the string.*/
int str_len(const char *s);
```

```c
/* str_ncomp - Compare characters of two strings*/
int str_ncomp(char *s1, char *s2, int k);
```

```c
/* reverse - A function to reverse the string*/
void reverse(char str[], int length);
```

```c
/* string_dup - Creates a duplicate of the string pointed to by str*/
char *string_dup(char *str);
```
