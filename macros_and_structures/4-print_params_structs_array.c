#include<stdlib.h>
#include "param_struct.h"
int nwords(char *s);
int print_char(char c);

void print_number(int n)
{
  int count,i,temp,j,x;
  temp=0; /*to store prev result*/
  i=n;
  for (count=0;i!=0;count++) /*count digits*/
    i=i/10;
  if (n<0)    /*if neg print '-'*/
    print_char('-');
  do{   /*do loop to work for 0*/
    i=n;
    x=count;
    for(;x>1;x--){  /*start from beginning*/
      i=i/10;
    }
    j=i-(temp*10);  /*subtract prev value*/
    temp=i;        /*save prev value*/
    if (j<0){  /*if neg digit make pos*/
      j=j*(-1);
    }
    print_char(j+48); /*+48 for ascii*/
    count--;
  }
  while(count>0);
}

void print_string(char *s)
{
  int i ;
  
  i = 0;
  while(s[i]!='\0')
    {
      print_char(s[i]);
      i++;
    }  
}

void print_params_structs_array(struct Param *params)
{
  int i;
  int j;
  int x;

  i = 0;
  while(params[i].str != NULL)
    {
      print_string(params[i].copy);
      print_char('\n');
      print_number(params[i].length);
      print_char('\n');
      x = nwords(params[i].copy);
      for(j = 0; j < x; j++)
	{
	  print_string(params[i].tab[j]);
	  if( j < x -1)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	}
      print_char('\n');
      i++;
    }
}
