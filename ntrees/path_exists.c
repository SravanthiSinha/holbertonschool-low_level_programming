#include <stdlib.h>
#include "tree.h"
#include <string.h>

int path_exists(NTree *tree, char **s)
{
  List *list;
  int i;

  for(i=1;s[i];i++)
    {
      list = tree->children;
      if(list == NULL)
	return 0;
      while(strcmp(list->node->str,s[i])!=0)
	{
	  if(list->next == NULL)
	    return 0;
	  list = list->next;
	}
	tree = list->node;
    }
  return 1;
}
