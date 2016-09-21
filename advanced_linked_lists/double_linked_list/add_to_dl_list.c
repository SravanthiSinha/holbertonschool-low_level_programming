#include <string.h>
#include "list.h"
#include <malloc.h>
#include <stdlib.h>

int add_end_dl_list(List **list, char *str)
{
  List *node;
  List *temp;

  node = *list;
  if(node != NULL)
    while(node->next!=NULL)
      node = node->next;
  
  temp = malloc(sizeof(List));
    if(temp != NULL)
      {
	temp->str = strdup(str);
	temp->next = NULL;
	temp->prev = node;
	if (node != NULL)
	    node->next = temp;
	else
	    *list = temp;
	return 0;
      }        
  return 1;
}

int add_begin_dl_list(List **list, char *str)
{

  List *temp;
  List *head;

  head = *list;
  temp = malloc(sizeof(List));
  
    if(temp != NULL)
      {
	temp->str = strdup(str);
	temp->prev = NULL;
	temp->next = head;
	if (head!= NULL)
	    head->prev = temp;
	*list = temp;
	return 0;
      }
    
  return 1;  
}
