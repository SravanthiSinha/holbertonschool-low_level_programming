#include <stdlib.h>
#include "lists.h"
#include "header.h"

/* The function print_string takes
 * an pointer to a char
 * and prints a string.
 * It takes a argument (char *) and
 * returns nothing (void)
 */
 void print_number(int n)
 {
   if(n > 10)
     print_number(n/10);
   _putchar(n%10 + 48);
 }

size_t print_listint(listint_t *list)
{

  listint_t *node;
  size_t i;

  i = 0;
  node = list;
  while(node != NULL)
    {
      print_number(node->n);
      if(node->next != NULL)
	{
	  _putchar(',');
	  _putchar(' ');
	}
      node = node->next;
      i++;
    }
  _putchar('\n');
  return i;
}
