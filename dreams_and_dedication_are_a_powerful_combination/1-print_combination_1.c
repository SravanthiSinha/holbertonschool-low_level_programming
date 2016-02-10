#include "my_functions.h"

void print_combination_1(void)
{
  int start=0;
  int end=9;
  int i;
  for(i=start;i<=end;i++) 
    {
    print_number(i);
    if(i!=end)
      {
	print_char(',');
	print_char(' ');
      }
    }
}
