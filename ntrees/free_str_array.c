#include<stdlib.h>

/*
 * A function that frees a 2 dimensional grid
 */
void free_str_array(char **array)
{						
  int i;
  char *str;
  i = 0;
  while(array[i])
    {
      str = array[i];
      free(str);
      i++;
    }
  free(array);
}
