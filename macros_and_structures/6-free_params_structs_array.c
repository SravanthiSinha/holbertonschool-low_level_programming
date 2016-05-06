#include <stdlib.h>
#include "param_struct.h"

/*a function that frees an array of struct Param*/
void free_params_structs_array(struct Param *array)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if(array != NULL)
    {
      while(array[i].str!=NULL)
	{
	  free(array[i].copy);
	  if(array[i].tab!=NULL)
	    {
	      while(array[i].tab[j]!=NULL)
		{
		  free(array[i].tab[j]);
		  j++;
		}
	      free(array[i].tab[j]);	
	    }
	  free(array[i].tab);

	  i++;
	}  
      free(array);
      }
}
