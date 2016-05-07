#include <stdlib.h>
#include "list.h"
#include <stdio.h>
int add_node(List **list, char *str);
void print_linkedlist(List **list)
{
  
  List *node;  
  node = *list; 
  while(node != NULL)
    {
      printf("%s\n",node->str);
      node = node->next;
    }
}
int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "Holberton") == 1)
    return (1);
  if (add_node(&list, "School") == 1)
    return (1);
  if (add_node(&list, "c is fun") == 1)
    return (1);

  print_linkedlist(&list);
  return (0);
}
