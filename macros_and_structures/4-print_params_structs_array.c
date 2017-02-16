#include "param_struct.h"
int print_char(char);
int str_len(char);
void print_str(char *s)
{
  int i;
  i = 0;
  while(s[i])
    {
      print_char(s[i]);
      i++;
    }
}

void print_num(int n)
{
  if(n>10)
      print_num(n/10);
  print_char(n%10 + 48);
}

void print_params_structs_array(struct Param *params)
{
  int i,x;
  i = 0;
  while(params[i].str)
    {
      print_str(params[i].copy);
      print_char('\n');
      print_num(params[i].length);
      print_char('\n');
      x = 0;
      while(params[i].tab[x])
	{
	  if(x != 0)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	  print_str(params[i].tab[x]);
	  x++;
	}
      print_char('\n');
      i++;
    }
}
