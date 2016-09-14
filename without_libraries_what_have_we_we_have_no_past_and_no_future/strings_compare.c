#include "holbertonschool.h"


/* The function strings_compare
 * compares two strings.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (int)
 */

int strings_compare(char *s1, const char *s2)
{
  int i,n1,n2,t,n;

  i = 0;
    
  n1=str_len(s1);
  n2=str_len(s2);
  
  n=(n1>=n2)?n1:n2;

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
