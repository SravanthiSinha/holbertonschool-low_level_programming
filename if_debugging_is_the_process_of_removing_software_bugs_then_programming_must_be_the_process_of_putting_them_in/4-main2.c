#include <stdio.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main(void)
{
  char *n = "1234567890";
  char *m = "1";
  char r[10];
  char *res;

  res = infinite_add(n, m, r, 10);
  if (res == 0)
    {
      printf("Error\n");
      return (1);
    }
  printf("%s + %s = %s\n", n, m, res);
  return (0);
}
