#include <stdlib.h>
#include "list.h"

int print_char(char c);

/* The function print_string takes 
 * an pointer to a char
 * and prints a string.
 * It takes a argument (char *) and
 * returns nothing (void)
 */

void print_string(char *str)
{
  int i=0;
  
  while(*(str+i)!='\0')
    {
      print_char(*(str+i));
      i++;
    }
}

void print_list(List *list)
{
  
  List *node;  
  node = list; 
  while(node != NULL)
    {
      print_string(node->str);
      if(node->next != NULL)
	print_char(',');
      node = node->next;
    }
  print_char('\n');
}
