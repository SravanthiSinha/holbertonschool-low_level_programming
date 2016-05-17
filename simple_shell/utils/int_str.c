#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char* int_str(int num, char* str)
{
  int i;
  bool isNegative;
  int rem;
  
  rem = 0;
  i = 0;
  isNegative= false; 
  if (num == 0)
    {
      str[i++] = '0';
      str[i] = '\0';
      return str;
    } 
  if (num < 0)
    {
      isNegative = true;
      num = -num;
    } 
  while (num != 0)
    {
      rem = num % 10;
      str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
      num = num/10;
    } 
  if (isNegative)
    str[i++] = '-'; 
  str[i] = '\0'; 
  reverse(str, i); 
  return str;
}
