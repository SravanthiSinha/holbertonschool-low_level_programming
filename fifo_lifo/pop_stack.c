#include <stdlib.h>
#include "stack.h"

char *pop_stack(Stack **s)
{
  Stack *node;
  if(*s == NULL)
    return NULL;
  else
    node = *s;
  *s = node->next;
  return node->str;   
}

