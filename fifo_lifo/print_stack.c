#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>


void print_stack_c(Stack *s)
{

  if(s == NULL)
    return;
  printf(", %s",s->str);
  print_stack_c(s->next);
}

void print_stack(Stack *s)
{
  if(s == NULL)
    return;
  else{
    printf("%s",s->str);
    print_stack_c(s->next);
  }
  printf("\n");
}
