#include "header.h"

/**
 * alloc_grid -  A function that returns a pointer to
 * a newly created 2 dimensional chars grid.
 * @row: No of rows in 2D array.
 * @col: No of columns in 2D array.
 * Description: A function that returns a pointer to
 * a newly created 2 dimensional chars grid
 * Return: pointer to a newly created 2 dimensional chars grid.
 */
char **alloc_grid(int row, int col)
{
	int __attribute__((unused)) i, j;
	char **array;

	/* Allocate array -first array of rows, then each row */
	array = (char **)malloc(row * sizeof(char *));
	for (i = 0; i < row; i++)
		array[i] = (char *)malloc(sizeof(char) * col);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			array[i][j] = 'O';

	return (array);
}

/**
 * print_grid -  A function that prints 2 dimensional chars grid.
 * @grid: The 2D array to be printed
 * @row: No of rows in 2D array.
 * @col: No of columns in 2D array.
 * Description: A function that prints 2 dimensional chars grid.
 */
void print_grid(char **grid, int row, int col)
{
	int i;
	int j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c", grid[i][j]);
			if (j < col - 1)
				printf("\t");
		}
		printf("\n");
	}
}

/**
 * free_grid -  A function that frees a 2 dimensional chars grid.
 * @grid: The 2D array to be freed.
 * @row: No of rows in 2D array.
 * Description: A function that frees a 2 dimensional chars grid.
 */
void free_grid(char **grid, int row)
{
	int i;
	char *currentIntPtr;

	for (i = 0; i < row; i++)
	{
		currentIntPtr = grid[i];
		free(currentIntPtr);
	}
	free(grid);
}
