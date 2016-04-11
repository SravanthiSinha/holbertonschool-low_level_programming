#include <stdlib.h>

/*
 * A  function that returns a pointer to
 * a newly created 2 dimensional integers grid
 */
int **alloc_grid(int x, int y)
{
  int  __attribute__((unused))i,j;  
  int **array ;

  /* Allocate array -first array of rows, then each row */
  array = (int **)malloc(x * sizeof(int *)); 

  for(i=0;i<y;i++)
    array[i] = (int *)malloc(sizeof(int) * y);

    if(array == NULL)
      return NULL;
    else
     {
      for(i = 0; i < x; i++)
	for(j = 0;j < y ; j++)
	      array[i][j]=0;
     }
   return array;
}

/*
void print_grid(int **grid, int x, int y) 
{
  int i,j;
  
  for(i = 0; i < x; i++)
    {
      for(j = 0; j < y; j++)
	{
	  printf("%d",grid[i][j]);
	  if(j < y - 1)
	    printf(", ");
	}
      printf("\n");
    }
}
*/
