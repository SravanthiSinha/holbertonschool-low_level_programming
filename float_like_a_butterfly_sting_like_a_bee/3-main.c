#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);

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

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = 402;
  print_grid(grid, 5, 5);
  return (0);
}
