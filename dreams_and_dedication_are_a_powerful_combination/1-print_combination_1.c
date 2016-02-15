#include "my_functions.h"

/* The function print_combination_1 takes no arguments
 * and prints it on one line - all possible
 * combinations of single-digit numbers in 
 * ascending order seperated by comma followe by a space. 
 * takes no argument
 * returns nothing (void)
 */
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
