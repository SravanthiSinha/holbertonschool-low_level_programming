#include "strings.h"
#include "printf.h"

int print_signed_decimal_int(signed int n)
/* print an signed decimal integer*/
{
  char s[100];
  if(n < 0){
    n = n * -1;
    print_character('-');
  }
  print_number(n);  
  int_str(n,s);
  return str_len(s);
}

int print_unsigned_decimal_int(unsigned int n)

{
  char s[100];
  print_number(n);  
  int_str(n,s);
  return str_len(s);
}

int print_unsigned_octal(unsigned int n)

{
  int i ;
  
  i = 0;
  print_oct(n);
  while(n != 0) {
    n = n/8;
    i++;
  }
  return i;
}

int print_unsigned_hexdecimal_integer(unsigned int n)

{
  int r,i,k;

  char c[]="0123456789abcdef";
  char s[]  ="00000000";
  i=7;
  k = 0;
  while(n>16)
    {
      r=n%16;
      s[i]=(c[r]);
      i--;
      n=n/16;
    }
  s[i]=c[n];

  i=0;

  while(*(s+i)!='\0')
    {
      if(s[i] != '0')
	{
	  print_character(*(s+i));
	  k++;
	}
      i++;
    }
  return k;
}

int print_unsigned_hexdecimal_integer_U(unsigned int n)

{
  int r,i,k;
  char c[]="0123456789ABCDEF";
  char s[]  ="00000000";

  i = 7;
  k = 0;
  while(n>16)
    {
      r=n%16;
      s[i]=(c[r]);
      i--;
      n=n/16;
    }
  s[i]=c[n];
  i=0;
  while(*(s+i)!='\0')
    {
      if(s[i] != '0')
	{
	  print_character(*(s+i));
	  k++;
	}
      i++;
    }
  return k;
}
