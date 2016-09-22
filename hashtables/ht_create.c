#include "hashtable.h"
#include "stdlib.h"

HashTable *ht_create(unsigned int size)
{
  HashTable *hashtable;
  unsigned int i;
  
  hashtable = malloc(sizeof(HashTable));
  if(hashtable ==NULL)
    return NULL;
  else
    {
      hashtable->size = size;
      hashtable->array = malloc(size*(sizeof(List)));
      if(hashtable->array ==NULL)
	return NULL;
      else
	{
	  for(i = 0 ;i < size; i++)
	    hashtable->array[i]=NULL;
	}
    }
  return hashtable;  
}
