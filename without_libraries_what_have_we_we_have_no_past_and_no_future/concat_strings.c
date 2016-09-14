#include "holbertonschool.h"

/* The function concat_strings 
 * concatenates two strings.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */


char *concat_strings(char * dest,const char *src)
{
  int i,n;

  i=0;
  n=str_len(dest);

  while(*(src+i)!='\0')
    {
      *(dest+i+n)=*(src+i);
      i++;
    }
  return dest  ;
}
