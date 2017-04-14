#include "header.h"
/*
 * A  function that returns a pointer to
 * a newly created 2 dimensional integers grid
 */
char **alloc_grid(int x, int y)
{
  int __attribute__((unused)) i, j;
  char **array;

  /* Allocate array -first array of rows, then each row */
  array = (char **)malloc(x * sizeof(int *));

  for (i = 0; i < y; i++)
    array[i] = (char *)malloc(sizeof(int) * y);

  if (array == NULL)
    return (NULL);
  else
  {
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
    array[i][j] = 0;
  }
  return (array);
}

void print_grid(char **grid, int x, int y)
{
  int i, j;

  for (i = 0; i < x; i++)
  {
    for (j = 0; j < y; j++)
    {
      printf("%c", grid[i][j]);
      if (j < y - 1)
    printf("\t");
    }
    printf("\n");
  }
}

/*
 * A function that frees a 2 dimensional grid
 */
void free_grid(char **grid, int h)
{
  int i;

  for (i = 0; i < h; i++)
  {
    char *currentIntPtr = grid[i];
    free(currentIntPtr);
  }
  free(grid);
}
