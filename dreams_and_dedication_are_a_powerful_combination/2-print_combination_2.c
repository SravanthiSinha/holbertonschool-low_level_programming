#include "my_functions.h"

/* The function print_combination_2 takes no arguments
 * and prints it on one line - all possible
 * combinations of two-digit numbers in 
 * ascending order seperated by comma followe by a space. 
 * takes no argument
 * returns nothing (void)
 */
void print_combination_2(void){
  int i,j;

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
