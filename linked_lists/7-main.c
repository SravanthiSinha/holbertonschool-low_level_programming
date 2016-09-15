#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);
void remove_from_list(List **list, int index);
void print_list(List *list);

int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "Holberton") == 1)
    return (1);
  if (add_node(&list, "School") == 1)
    return (1);
  if (add_node(&list, "98 Battery St.") == 1)
    return (1);
  if (add_node(&list, "CA 94111") == 1)
    return (1);
  print_list(list);
  remove_from_list(&list, 1);
  print_list(list);
  return (0);
}
