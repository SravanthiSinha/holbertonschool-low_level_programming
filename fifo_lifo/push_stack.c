#include "stack.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int push_stack(Stack **s, char *data)
{
  Stack *last;

  last = *s;
  if(*s == NULL)
    {
      *s = malloc(sizeof(Stack));
      if(*s != NULL)
	{
	  (*s)->str = strdup(data);
	  (*s)->next = NULL;
	  return 0;
	}
      return 1;
    }
  else
    {
      *s = malloc(sizeof(Stack));
      if(*s != NULL)
	{
	  (*s)->str = strdup(data);
	  (*s)->next = last;
	  return 0;
	}
      return 1;
    }
  return 1;
}
