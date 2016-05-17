#include <stdlib.h>

void free_split(char **grid)
/*A function that frees an array of strings */
{
	int i;
	i = 0;
	while(grid[i] != NULL){
		free(grid[i]);
		i++;
	}
	free(grid[i]);
	free(grid);
}
