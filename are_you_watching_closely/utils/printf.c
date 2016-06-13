#include <stdarg.h>
#include "printf.h"
#include "strings.h"

int printf(const char *format, ...)
/*Recode the function printf of the C library*/
{

  va_list ap;
  int i;
  int len;
  int p;

  va_start(ap,format);
  i = 0;
  p = 0;
  len = str_len(format);
  while(format[i])
    {
      if(format[i] =='%' && i < len)
	{
	  if(format[i+1] == 'i' || format[i+1] == 'd')
	    p += print_signed_decimal_int(va_arg(ap,signed int));
	  else if(format[i+1] == 'u')
	    p += print_unsigned_decimal_int(va_arg(ap,unsigned int));
	  else if(format[i+1] == 'o')
	    p += print_unsigned_octal(va_arg(ap,unsigned int));
	  else if(format[i+1] == 'x')
	    p += print_unsigned_hexdecimal_integer(va_arg(ap,unsigned int));
	  else if(format[i+1] == 'X')
	    p += print_unsigned_hexdecimal_integer_U(va_arg(ap,unsigned int));
	  else if(format[i+1] == 'c')
	    p += print_character((char)va_arg(ap,int));
	  else if(format[i+1] == 's')
	    p += print_string(va_arg(ap,char *));
	  else if(format[i+1] == 'p')
	    p += print_pointeraddress(va_arg(ap,int *));
	  else if(format[i+1] == 'b')
	    p += print_unsigned_binary(va_arg(ap,unsigned int));
	  else if(format[i+1] == '%')
	    p += print_character('%');
	  else 
	    {
	      print_character('%');
	      print_character(format[i+1]);
	      p +=2;
	    }
	  i++;
	}
      else 
	{
	  p++;
	  print_character(format[i]);
	}
      i++;
    }
  va_end(ap);
  return p;
}
