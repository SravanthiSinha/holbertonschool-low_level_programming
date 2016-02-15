#include "my_functions.h"

/* The function print_combination_1 takes no arguments
 * and prints it on one line - all possible
 * combinations of three-digit numbers in 
 * ascending order seperated by comma followe by a space. 
 * takes no argument
 * returns nothing (void)
 */

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
