#include "header.h"

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

char **getMap(FILE *file, int *row, int *col)
{
  char **map;
  int i, j;
  char *ch;
  char line[256];

  i = 0, j = 0;
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
