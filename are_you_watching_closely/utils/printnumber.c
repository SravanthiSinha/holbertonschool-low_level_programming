#include "printf.h"
#include "strings.h"

void print_number(unsigned int n)
{
  if(n > 10)
    print_number(n/10);
  print_character(n%10 + 48);
}
