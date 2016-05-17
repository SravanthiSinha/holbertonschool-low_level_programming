#include <stdlib.h>
/*
* A function that frees a 2 dimensional grid
*/
void free_split(char **grid)
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
