#include <stdio.h>
#include <stdlib.h>

char **string_split(char *);

void print_tab(char **grid)   
{
  int i;
  
  while(grid[i] != NULL)
    {
      printf("%s\n",grid[i]);
      i++;
    }
}

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

int main(void)
{
  char **tab;

  tab = string_split("Holberton School         #cisfun");
  print_tab(tab);
  free_tab(tab);
  return (0);
}
