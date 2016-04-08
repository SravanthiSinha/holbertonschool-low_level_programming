#include<stdlib.h>
#include<stdio.h>
/*
 * A function that frees a 2 dimensional grid
 */
void free_grid(int **grid, int h)
{						
  int i;


  for(i = 0; i < h; i++)
    {
      int* currentIntPtr = grid[i];
      free(currentIntPtr);
    }
  free(grid);
}
