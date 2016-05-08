#include <stdlib.h>
#include "list.h"
#include<stdio.h>

int str_len(char *s);
int add_node(List **list, char *content);
char *string_dup(char *s);

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


/*a function that creates a node and then inserts it in a list at a specific index*/
int insert_in_list(List **list, char *content, int index)
{
  int size;
  List *node;
  List *temp;
  List *new;
  int i;

  i = 0;
  size = list_size(*list);
  if(index < 0)
    return (1);
  else if(index >= size || index == 0)
    return (add_node(list,content));
  else
    {
     node = *list;
     temp = *list;
      while(i < index)
	{
	  temp = node;
	  node = node->next;
	  i++;
	}      
      new = malloc(sizeof(List));
      if( new == NULL)
	return 1;
      new->str = string_dup(content);
      new->next = node;
      temp->next = new;    
      return (0);
    }
  
  return (1); 
}
