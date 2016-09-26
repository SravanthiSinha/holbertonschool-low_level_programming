#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>


void print_btree(BTree *tree)
{

  if(tree ==NULL)
    return;
  print_btree(tree->left);
  printf("%s\n",tree->str);
  print_btree(tree->right);
}
