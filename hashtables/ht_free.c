#include "hashtable.h"
#include <stdlib.h>

void ht_free(HashTable *hashtable)
{
  unsigned int i;
  List *node;
  List *temp;

  node = NULL;
  temp = NULL;
  
  if(hashtable != NULL)
    {
      if(hashtable->array)
	{
	  for(i = 0; i< hashtable->size; i++)
	    {
	      node = hashtable->array[i];
	      while(node!=NULL)
		{
		  free(node->key);
		  free(node->value);
		  temp = node;
		  node = node->next;
		  free(temp);	  
		}
	    }
	  free(hashtable->array);
	}
      free(hashtable);
    }
}
