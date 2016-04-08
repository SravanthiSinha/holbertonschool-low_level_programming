#include <stdlib.h>
#include <stdio.h>


/*
 * A  function that returns a pointer to
 * a newly created 2 dimensional integers grid
 */



int **alloc_grid(int x, int y)
{
  int  __attribute__((unused))i,j;
  
  int **array ;
  array = (int **)malloc(x * sizeof(int *));
  array[0] = (int *)malloc(sizeof(int) * x * y);
 
  for(i = 0; i < x; i++)
    array[i] = (*array + y * i);
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
