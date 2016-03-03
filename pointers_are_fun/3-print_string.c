#include<stdio.h>

void print_string(char *str)
{
  int i=0;
  while(*(str+i)!='\0')
    {
      printf("%c",*(str+i));
      i++;
    }
}
