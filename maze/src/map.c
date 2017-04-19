#include "header.h"

/**
 * countlines - Takes FILE as input and returns the no of lines in the file.
 * @fp: Takes FILE as input
 * Description: Takes FILE as input and returns the no of lines in the file.
 * Return: no of lines in the file.
 */
int countlines(FILE *fp)
{
	int count;
	char c;

	count = 0;
	/*Extract characters from file and store in character c */
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') /* Increment count if this character is newline */
			count = count + 1;
	rewind(fp);
	return (count);
}
/**
 * countCol - Takes FILE as input, returns the no of columns in the first line.
 * @fp: Takes FILE as input
 * Description: Takes FILE as input, returns the no of lines in the first line.
 * Return: no of columns in the first line.
 */
int countCol(FILE *fp)
{
	int count;
	char c;

	count = 0;
	/*Extract characters from file and store in character*/
	for (c = getc(fp); c != '\n'; c = getc(fp))
		if (c == ',') /*Increment count if this character is newline*/
			count = count + 1;
	rewind(fp);
	return (count);
}

/**
 * getMap - Takes FILE as input and returns 2D array.
 * @file: Takes FILE as input
 * @row: no of rows in a 2D array.
 * @col: no of columns in a 2D array.
 * Description: Takes FILE as input and returns 2D array.
 * Return: returns 2D array of chars.
 */
char **getMap(FILE *file, int *row, int *col)
{
	char **map;
	int i;
	int j;
	char *ch;
	char line[256];

	i = 0;
	j = 0;
	*row = countlines(file);
	*col = countCol(file) + 1;
	map = alloc_grid(*row, *col);
	while (fgets(line, sizeof(line), file))
	{
		ch = strtok(line, ",");
		j = 0;
		while (ch != NULL)
		{
			map[i][j] = *ch;
			j++;
			ch = strtok(NULL, ",");
		}
		i++;
	}
	return (map);
}
