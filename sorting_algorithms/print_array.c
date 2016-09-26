#include <stdlib.h>

int print_char(char c);

void print_string(char *s)
{
  int i;
  i = 0;
  
  while(s[i])
    {
    print_char(s[i]);
    i++;
    }
}

void print_array_str(char **a)
{
  int i;

  i = 0;
  
  for(i = 0; a[i]!= NULL; i++)
    {
      print_string(a[i]);
      if(a[i+1])
      print_char(',');
    }
  print_char('\n');
}

void print_number(int n)
{
  if(n >= 10)
    print_number(n/10);
  print_char(n%10 + 48);
}

void print_array(int *a, int size)
{
  int i;

  for(i = 0; i < size; i++)
    {
      print_number(a[i]);
      if(a[i+1])
	print_char(',');
    }
  print_char('\n');
}
