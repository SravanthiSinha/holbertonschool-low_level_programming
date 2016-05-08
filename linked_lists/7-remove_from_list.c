#include <stdlib.h>
#include "list.h"
#include<stdio.h>


int list_size(List *list)
{
  List *node;
  int size;
  
  size = 0;
  node = list;
  while(node!= NULL)
    {
      size++;
      node = node->next;
    }
  
  return (size);
}

/* a function that removes and frees a node from a list at a specific index*/
void remove_from_list(List **list, int index)
{
  int size;
  int i;
  List *node;
  List *left;
  List *right;

  i = 0;
  size = list_size(*list);
  node = *list;
  if(index == 0)  
    {
     *list = node->next;      
    }
  else if(index < size)
    {
      while(i < index)
	{
	  left = node;
	  right = node->next;
	  node = node->next;
	  i++;
	}
      
      left->next = right -> next;
      free(node->str);
      free(node);
    }
  
}
