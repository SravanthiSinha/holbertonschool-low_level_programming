#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* The function 'print_stack' is provided */
void print_stack(const Stack *);

int push_stack(Stack **, char *);
char *pop_stack(Stack **);

int main(int ac, char **av)
{
  Stack *stack;
  int i;
  char *str;

  stack = NULL;
  i = 0;
  while (i < ac)
    {
      push_stack(&stack, av[i]);
      ++i;
    }
  print_stack(stack);
  str = pop_stack(&stack);
  printf("%s\n", str);
  print_stack(stack);
  str = pop_stack(&stack);
  printf("%s\n", str);
  print_stack(stack);
  str = pop_stack(&stack);
  printf("%s\n", str);
  print_stack(stack);
  return (0);
}
