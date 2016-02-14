#include "my_functions.h"

void print_combination_3(void);

void print_combination_3(void){
  int i,j,k;
  for(i=0;i<=9;i++)
    {
      for (j=1;j<=9;j++)
	{
	  for (k=2;k<=9;k++)
	    {
	      if(i<=j && i!=j && j<=k && j!=k)
		{
		  print_number(i);
		  print_number(j);
		  print_number(k);
		  if((i<7) && (j<=8) && (k<=9))
		    {
		      print_char(',');
		      print_char(' ');
		    }
		}
	    }
	}
    }
}
