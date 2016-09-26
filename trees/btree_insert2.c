#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>

int btree_insert(BTree **tree, char *data);

int btree_insert(BTree **tree, char *data)
{
  BTree *root;
  BTree *node;
  BTree *child;
  
  root = *tree;
  node = *tree;
  child = malloc(sizeof(BTree));
  if(child != NULL)
    {
      child->str = strdup(data);
      child->left = NULL;
      child->right = NULL;
      if(root == NULL)
	{
	  *tree = child;
	  return 0;
	}
      else
	{
 	  while(node)
	    {
	      if(strcmp(child->str,node->str) >= 0)
		{
		  if(node->right)
		    node = node->right;
		  else
		    {
		      node->right= child;
		      return 0;
		    }
		}
	      else if(strcmp(child->str,node->str) < 0)
		{
		  if(node->left)
		    node = node->left;
		  else
		    {
		      node->left = child;
		      return 0;
		    }
		}
	    }
	}
    }
  
  return 1;
}
