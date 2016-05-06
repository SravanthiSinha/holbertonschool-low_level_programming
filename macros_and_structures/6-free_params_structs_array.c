#include <stdlib.h>
#include "param_struct.h"

/*
 * A function that frees a 2 dimensional grid
 */
void free_tab(char **grid)
{
  int i;
   
  i = 0;
  while(grid[i] != NULL)
    {
      free(grid[i]);
      i++;
    }
  free(grid[i]);
  free(grid);
}

/*a function that frees an array of struct Param*/
void free_params_structs_array(struct Param *array)
{
  int i;

  i = 0;

  if(array != NULL)
    {
      while(array[i].str!=NULL)
	{
	  free_tab(array[i].tab);
	  free(array[i].copy);
	  i++;
	}  
      free(array);
      }
}
