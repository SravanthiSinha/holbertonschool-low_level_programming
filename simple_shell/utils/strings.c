#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
typedef int bool;
#define true 1
#define false 0

void swap(char *a,char *b)
{
  char c;

  c = *a;
  *a = *b;
  *b = c;
}
void reverse(char str[], int length)
{
  int start = 0;
  int end = length -1;
  while (start < end)
    {
      swap(&(str[start]), &(str[end]));
      start++;
      end--;
    }
}
 
char* int_str(int num, char* str)
{
  int i = 0;
  bool isNegative = false;

  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
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
      int rem = num % 10;
      str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
      num = num/10;
    }
 
  if (isNegative)
    str[i++] = '-';
 
  str[i] = '\0'; 
  reverse(str, i);
 
  return str;
}

/*
 *  a function that concatenates two strings.
 */
char *string_concat(char *s1, char *s2)
{
 
  int len,len2,i,j;
  char *s;

  i = 0;
  j=0;
  len = str_len(s1);
  len2= str_len(s2);  
  s = malloc(sizeof(*s) * (len + len2 + 1) );
  

  if (s == NULL)
    {
      return ( NULL);
    }
  else
    {
      while(i < len)
	{
	  s[i]= s1[i];
	  i++;
	}

      while(j < len2)
	{
	  s[i] = s2[j];
	  i++;
	  j++;
	}
      s[i] = '\0';
    }
  return s; 
  
}
  

int str_len(const char *s)
{
  int i;
  
  i = 0;
  while(s[i])
    {
      i++;
    }  
  return (i);  
}


int str_ncomp(char *s1, char *s2, int k)
{
  int i,n1,n2,t,n;

  i = 0;
  t = 0;  
  n1=str_len(s1);
  n2=str_len(s2);
  
  n = (n1 >= n2) ? n1 : n2;
  n = (k > n) ? n : k;
  while(i<n)
    {
      if(s1[i]!=s2[i])
	{
	  t=s1[i]-s2[i];
	  break;
	}
      else{
	t=0;
      }
      i++;
    }
  return (t);

}
