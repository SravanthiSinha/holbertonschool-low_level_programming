#include<stdio.h>

char lowercase(char c)
{
  if(c>=65 && c<=90)
    return c+32;
  else return c;
}
