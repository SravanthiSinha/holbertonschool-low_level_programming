#include "queue.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int push_queue(Queue **q, char *data)
{
  if(*q == NULL)
    {
      *q = malloc(sizeof(Queue));
      if(*q != NULL)
	{
	  (*q)->str = strdup(data);
	  (*q)->next =NULL;
	  return 0;
	}
      return 1;
    }
  else
    return push_queue(&(*q)->next,data);
  return 1;
}
