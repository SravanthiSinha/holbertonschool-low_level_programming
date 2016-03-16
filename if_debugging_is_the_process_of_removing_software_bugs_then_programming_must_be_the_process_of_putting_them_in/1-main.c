#include <stdio.h>
char *cap_string(char *);

int main(void)
{
  char s[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\n";
  char *p;

  p = cap_string(s);
  printf("%s", p);
  printf("%s", s);
  return (0);
}
