#include "header.h"

int **getAltitudes(FILE* file)
{
  int **altitudes;
  int i,j;
  char *ch;
  char line[256];
  
  i = 0,j = 0;

  altitudes = alloc_grid(row,col);
  
  while (fgets(line, sizeof(line), file))
    {
      ch = strtok(line, " ");
      j = 0;
      while (ch != NULL)
	{
	  altitudes[i][j] = atoi(ch);
	  j++;
	  ch = strtok(NULL, " ");
	}
      i++;
    }
  
  return altitudes;
}
