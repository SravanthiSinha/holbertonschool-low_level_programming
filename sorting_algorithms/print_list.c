#include <stdlib.h>
#include "list.h"

int print_char(char c);
void print_string(char *str);
void print_list(List *list);
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
  int first;
  
  node = list;
  first =1;
  while(node != NULL)
    {
      if(!first)
	print_string(", ");
      else
	first = 1;
      print_string(node->str);
      node = node->next;
    }
  print_char('\n');
}
