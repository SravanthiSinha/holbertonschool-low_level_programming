#include <stdlib.h>
#include "tree.h"

void ntree_free(NTree *tree);
void free_list(List *head)
{
  List *node;
  List *temp;
  node = head;
  while(node)
    {
      temp = node;
      node = node->next;
      ntree_free(temp->node);
      free(temp);
    }
}

void ntree_free(NTree *tree)
{
  NTree *node,*temp;
  node = tree;

  if(node)
    {
      temp = node;
      while(node->children)
	{
	  ntree_free(node->children->node);
	  node->children = node->children->next;
	  free_list(temp->children);		  
	  free(temp->str);
	  temp = node;
	}
      free(temp->str);
      free(temp);
    }

  return ;
}

