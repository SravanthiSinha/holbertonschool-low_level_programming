#include <stdio.h>
#include "param_struct.h"
int nwords(char *s);
void print_grid(char **grid,int x) 
{
  int i;
  
  for(i = 0; i < x; i++)
    {
      printf("%s",grid[i]);
      if( i < x -1)
      printf(", ");
    }
      printf("\n");

}

void print_params_structs_array(struct Param *params)
{
  int i;

  i = 0;
  while(params[i].str != NULL)
    {
      printf("%s\n",params[i].str);
      printf("%d\n",params[i].length);
      print_grid(params[i].tab,nwords(params[i].str));
      i++;
    }
}
