#include<stdio.h>
/* The function string_copy
 * copies a string.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */

char *string_copy(char * dest, char *src)
{
  int i;

  i=0;
  while((*(src+i)!='\0'))
    {
      *(dest+i)=*(src+i);
      i++;
    }
  *(dest+i)='\0';
  return dest  ;
}

int main(void)
{

      char s1[98];
      char *p;
      p = string_copy(s1, "First, solve the problem. Then, write the code\n");
      printf("%s", s1);
      printf("%s", p);
      return (0);
    
}
