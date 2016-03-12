#include <stdio.h>
int string_to_integer(char *s);

int main(void)
{
  int n;

  n = string_to_integer("98");
  printf("%d\n", n);
  n = string_to_integer("-402");
  printf("%d\n", n);
  n = string_to_integer("        ++++++-----+++++--98");
  printf("%d\n", n);
  n = string_to_integer("2147483647");
  printf("%d\n", n);
  n = string_to_integer("0");
  printf("%d\n", n);
  n = string_to_integer("-21474836481");
  printf("%d\n", n);
  n = string_to_integer("2147483648");
  printf("%d\n", n);
  n = string_to_integer("34234232147483648");
  printf("%d\n", n);
  n = string_to_integer("Suite 402");
  printf("%d\n", n);
  n = string_to_integer("      +    +   -   -98 Battery Street; San Francisco, CA 94111 - USA         ");
  printf("%d\n", n);
  n = string_to_integer("---++++ - Sui - te -  402 #cisfun :)");
  printf("%d\n----File used to test the task below---\n", n);
  n = string_to_integer("-+98");
  printf("Expected: -98\n");
  printf("%d\n", n);
  n = string_to_integer("-402");
  printf("Expected: -402\n");
  printf("%d\n", n);
  n = string_to_integer("        ++++++-----+++++--+98");
  printf("Expected: -98\n");
  printf("%d\n", n);
  n = string_to_integer("+++++    + 2147483647");
  printf("Expected: 2147483647\n");
  printf("%d\n", n);
  n = string_to_integer("+0");
  printf("Expected: 0\n");
  printf("%d\n", n);
  n = string_to_integer("+-+2147483648------1");
  printf("Expected: -2147483648\n");
  printf("%d\n", n);
  n = string_to_integer("--2147483648-");
  printf("Expected: 0\n");
  printf("%d\n", n);
  n = string_to_integer("--34234232147483648   402 hello");
  printf("Expected: 0\n");
  printf("%d\n", n);
  n = string_to_integer("Su-ite 402");
  printf("Expected: -402\n");
  printf("%d\n", n);
  n = string_to_integer("      +    +   -   -98 Battery Street; San Francisco, CA 94111 - USA         ");
  printf("Expected: 98\n");
  printf("%d\n", n);
  n = string_to_integer("---++++ - Sui - te -  402 #cisfun :)");
  printf("Expected: 402\n");
  return (0);
}
