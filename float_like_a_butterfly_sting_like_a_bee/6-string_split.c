#include <stdlib.h>
#include <stdio.h>

/* The function str_len takes a string
 * and returns the length of string
 * It takes a argument (char *) and
 * returns an argumenet (int)
 */

int str_len(char *str)
{
  int len = 0;

  while(*(str + len)!='\0')
    {
      len++;
    }

  return len;
}


int nwords(char *str)
{
  int i,n,len; 
  i = 0 ;
  n = 0 ;
  len = str_len(str);

  while(str[i] != '\0')
    {
    if( str[i] >= 33 && str[i + 1] == 32 &&  i <  len)
      n++;

    i++;
    }
  if(str[i -1] >= 33 && str[i] == '\0')
    n++;
  
  return n;
}


/*  a function that splits each word 
 * of a string and stores them in a array of strings.*/
char **string_split(char *str)
{  
  char **tab;
  int i,j,k,l,m,n;    
  k = 0; l = 0; m =0;
  n = nwords(str);
  
  tab =(char **)malloc( n * sizeof(char *));   
  if(tab == NULL)  return NULL;
  for ( i = 0 ; i < n ; i ++)
    {
      j = 0; l = 0;
      while( str[k] != 32)
	{
	  j++;  k++;
	}
      tab[i] = (char *)malloc(sizeof(char) * j);     
      if(taby == NULL)	return NULL;
      while(l < j)
	{
	  tab[i][l]= str[m];
	  l++; 	  m++;
	}      
      tab[i][l]='\0';
      while (str[k] == 32)
	{
	  k++;
	  m++;
	}
    }
  return tab;  
}
