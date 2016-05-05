#include "str_struct.h"
#include <stdio.h>
int print_char(char c);

int get_len(unsigned long n)
{
  int l;

  l = 1;
  while(n / 10 )
    {
      l++;
      n = n / 10;
    }
  return l;
}

unsigned long power(unsigned long x, int y)
{
  unsigned long result =1;
  while(y--)
    result = result * x;
  return result;
}

void print_number(int n)
{
  int len;
  int p;
  unsigned long no;
  unsigned long q;

  if (n == 0)
    print_char('0');
  else if(n < 0)
    {
      no = (unsigned long) n * -1;
      print_char('-');
    }  
  else
    {
      no = (unsigned long)n;
    }  
  if(no > 0)
    {    
      len=get_len(no);
      p = len - 1;
      while(p <= len && no!=0 )
	{
	  q = no/power(10, p);
	  print_char(q + 48 );    
	  no = no - q * power(10, p);
	  p--;
	  len=get_len(no);
	} 
    }
}

void print_string(char *s)
{
  int i ;
  
  i = 0;
  while(s[i]!='\0')
    {
      print_char(s[i]);
      i++;
    }  
}


/* prints the conenets of sturcture String
   it takes struct String
   has no output arguement*/
void print_string_struct(struct String *str)
{
  if(str!=NULL)
    {
      print_string(str->str);
      print_char(',');
      print_char(' ');
      print_number(str->length);
      print_char('\n');
    }
}

