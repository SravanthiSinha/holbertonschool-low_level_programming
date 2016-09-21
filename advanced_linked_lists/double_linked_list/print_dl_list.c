#include "list.h"
#include <stdlib.h>

int print_char(char);
void print_string(char *s);

void print_string_n(char *s)
{
  print_string(s);
  print_char('\n');
}

void print_string_tab(char *s)
{
  print_char('\t');
  print_string_n(s);
}

void print_dl_list(List *list)
{
  List *node;

  node = list;
  while(node != NULL)
    {
      print_string_n(node->str);
      if(node->prev != NULL)
	  print_string_tab(node->prev->str);
      else
	print_string_tab("NULL");
      if(node->next != NULL)
	  print_string_tab(node->next->str);
      else
      print_string_tab("NULL");
      node = node->next;
    }
}
