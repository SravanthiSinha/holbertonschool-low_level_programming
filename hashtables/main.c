#include "hashtable.h"
#include <stdio.h>

HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
char *ht_get(HashTable *hashtable, const char *key);
void ht_free(HashTable *hashtable);

int main(void)
{
  HashTable *hashtable;
  int a;

  hashtable = ht_create(3);
  
  if(hashtable != NULL)
    {
      a = ht_put(hashtable,"steve","jobs");
      if(a == 0)
	printf("%s\n",ht_get(hashtable,"steve"));
      a = ht_put(hashtable,"sri","sra");
      if(a == 0)
	printf("%s\n",ht_get(hashtable,"sri"));
      a = ht_put(hashtable,"steve","steve");
      if(a == 0)
	printf("%s\n",ht_get(hashtable,"steve"));
      a = ht_put(hashtable,"steve","ted");
      if(a == 0)
	printf("%s\n",ht_get(hashtable,"steve"));
      a = ht_put(hashtable,"steve","roy");
      if(a == 0)
	printf("%s\n",ht_get(hashtable,"steve"));
      ht_free(hashtable);
    }
  
  
  return 0;
}
