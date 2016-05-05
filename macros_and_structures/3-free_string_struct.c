#include <stdlib.h>
#include "str_struct.h"

void free_string_struct(struct String *str)
{
  free(str);
}
