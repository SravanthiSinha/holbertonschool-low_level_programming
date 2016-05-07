#include <stdlib.h>
#include "list.h"

List *params_to_list(int ac, char **av);
int print_char(char c);
void print_list(List *list);


int main(int ac, char **av)
{
  List *params_list;

  params_list = params_to_list(ac, av);
  if (params_list == NULL)
    return (1);
  print_list(params_list);
  return (0);
}
