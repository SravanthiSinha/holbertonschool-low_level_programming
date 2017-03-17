#include <stdlib.h>
#include <string.h>
#include "tree.h"


void ntree_free(NTree *ntree)
{
  NTree *node;
  List *list,*temp;
  node = ntree;

  if(node)
    {
      list =  node->children;
      while(list)
	{	  
	  temp = list;
	  list = list->next;
	  ntree_free(temp->node);
	  free(temp);
	}
      free(node->str);
      free(node);
    }

}

