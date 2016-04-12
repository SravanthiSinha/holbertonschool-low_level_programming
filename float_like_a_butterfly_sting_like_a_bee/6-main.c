#include <stdio.h>
#include <stdlib.h>

char **string_split(char *);

void print_tab(__attribute__((unused)) char **tab)   
{
  

}

/*
 * A function that frees a 2 dimensional grid
 */
void free_tab(__attribute__((unused)) char **grid)
{

}

int main(void)
{
  __attribute__((unused)) char **tab;

  tab = string_split("Holberton School         #cisfun");
  print_tab(tab);
  free_tab(tab);
  return (0);
}
