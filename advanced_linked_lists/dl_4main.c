#include <stdlib.h>
#include "list.h"

List *array_to_dl_list(char **);
void free_dl_list(List *);

int main(__attribute__((unused))int ac, char **av)
{
  List *list;

  list = array_to_dl_list(av);
  if (list == NULL)
    return (1);
  free_dl_list(list);
  return (0);
}
