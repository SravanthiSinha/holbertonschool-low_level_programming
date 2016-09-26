#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>

void btree_free(BTree *tree)
{
  if(tree != NULL)
    {
      free(tree->str);
      btree_free(tree->right);
      btree_free(tree->left);
      free(tree);
      return;
    }
  return ;
}
