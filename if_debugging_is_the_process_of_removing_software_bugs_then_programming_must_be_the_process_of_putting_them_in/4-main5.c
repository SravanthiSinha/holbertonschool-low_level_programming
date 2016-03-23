#include <stdio.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main(void)
{
  char *n = "34642357645763473476347";
  char *m = "2362624561";
  char r[32];
  char *res;

  res = infinite_add(n, m, r, 32);
  if (res == 0)
    {
      printf("Error\n");
      return (1);
    }
  printf("%s + %s = %s\n", n, m, res);
  return (0);
}
