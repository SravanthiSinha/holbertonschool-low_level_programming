#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

BTree *array_to_btree(char **array);
int btree_insert(BTree **tree, char *data);

BTree *array_to_btree(char **array)
{
  BTree *btree;
  int i;
  
  btree = NULL;
  for(i = 0; array[i]; i++)
    {
      if(btree_insert(&btree,array[i]))
	return NULL;
    }
  
  return btree;	
}
