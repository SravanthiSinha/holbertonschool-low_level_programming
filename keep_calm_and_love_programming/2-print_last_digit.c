#include<stdio.h>

int absolute(int n){
  if(n<0) return -n;
  else return n;
}

void print_last_digit(int n)
{
  printf("%d",absolute(n%10));
}

