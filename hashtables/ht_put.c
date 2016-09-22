#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
  unsigned int hashcode;
  List *head;
  List *temp;
  
  hashcode = hash(key,hashtable->size);
  head = hashtable->array[hashcode];
  
  temp = malloc(sizeof(List));

  if(temp != NULL)
    {
      temp->key = strdup(key);
      temp->value = strdup(value);
      temp->next = head;
      hashtable->array[hashcode] = temp;
      return 0;
    }
    return 1;  
}
