#include <stdlib.h>
#include "queue.h"

char *pop_queue(Queue **q)
{
  Queue *node;
  if(*q == NULL)
    return NULL;
  else
    node = *q;
  *q = node->next;
  return node->str;   
}

