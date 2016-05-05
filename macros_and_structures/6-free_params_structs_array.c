#include <stdlib.h>
#include "param_struct.h"

/*a function that frees an array of struct Param*/
void free_params_structs_array(struct Param *array)
{
  /*  int i ;

  i = 0;
  while(array[i].str!=NULL)
    {
      free(array[i]);
      }*/
  
  free(array);
}
