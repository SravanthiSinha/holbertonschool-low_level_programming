#include <stdlib.h>

void sort_str_array(char **);
void print_array_str(char **);

int main(void)
{
  char *array[] = {"San Francisco", "California", "School", "Holberton", "San Marcos",NULL};

  print_array_str(array);
  sort_str_array(array);
  print_array_str(array);
  return (0);
}
