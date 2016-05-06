#include <stdio.h>
#include "param_struct.h"
int nwords(char *s);
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

/*
void print_grid(char **grid,int x) 
{
  int i;
  for(i = 0; i < x; i++)
    {
      printf("%s",grid[i]);
      if( i < x -1)
      printf(", ");
    }
      printf("\n");
  

      }*/

void print_params_structs_array(struct Param *params)
{
  int i;
  int j;
  int x;

  i = 0;
  while(params[i].str != NULL)
    {
      print_string(params[i].copy);
      print_char('\n');
      print_number(params[i].length);
      print_char('\n');
      /*print_grid(params[i].tab,nwords(params[i].copy));*/
      x = nwords(params[i].copy);
      for(j = 0; j < x; j++)
	{
	  print_string(params[i].tab[j]);
	  if( j < x -1)
	    print_char(',');
	}
      print_char('\n');
      i++;
    }
}
