#include "my_functions.h"

void print_combination_2(void);

void print_combination_2(void){
  int i=0;
  int j=0;
  for(i=0;i<=9;i++)
    {
      for (j=1;j<=9;j++)
	{
	  if(i<=j && i!=j)
	    {
	      print_number(i);
	      print_number(j);
	      if((i<8) && (j<=9))
		{
	       print_char(',');
              print_char(' ');
		}
	    }
	}
    }
}
