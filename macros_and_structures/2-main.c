#include "str_struct.h"

struct String *string_to_struct(char *str);
void print_string_struct(struct String *str);

int main(void)
{
  struct String *str;

  str = string_to_struct("Holberton");
  print_string_struct(str);
  str = string_to_struct("C is fun");
  print_string_struct(str);
  return (0);
}
