#include <stdlib.h>
#include "list.h"

List *array_to_cl_list(char **);
void print_cl_list(List *);

int main(__attribute__((unused))int ac, char **av)
{
  List *list;

  list = array_to_cl_list(av);
  if (list == NULL)
    return (1);
  print_cl_list(list);
  return (0);
}
