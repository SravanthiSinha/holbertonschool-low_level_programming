#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

char *ht_get(HashTable *hashtable, const char *key){
  unsigned int hashcode;
  List *head;
  List *node;
  
  hashcode = hash(key,hashtable->size);

  head = hashtable->array[hashcode];
  node = head;

  while(node)
    {
      if(hash(node->key,hashtable->size) == hashcode)
	if(strcmp(node->key,key)==0)
	   return node->value;
	node = node->next;
    }
  return NULL;  
}
