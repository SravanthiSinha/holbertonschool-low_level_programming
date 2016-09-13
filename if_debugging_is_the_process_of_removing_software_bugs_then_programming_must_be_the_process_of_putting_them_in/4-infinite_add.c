#include<limits.h>

int str_len(char *s)
{
  int i;
  i = 0;
  while(s[i])
    i++;
  return i;
}

void shift_left(char *s)
{
  int i ;
  for(i = 0;i < str_len(s);i++)
    s[i] = s[i+1];
  s[i] = '\0';
}

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
  int l1;
  int l2;
  int i;
  int j;
  int k;
  int carry;
  carry = 0;
  l1=str_len(n1);
  l2=str_len(n2);
  if(l1 >= size_r || l2 >= size_r)
    return 0;
  else
    {
      if(l1 > l2)
	k = l1 + 1;
      else
	k = l2 + 1;
      r[k]='\0';
      k--;
      for(i = l1-1,j = l2-1; i >= 0 && j >= 0 && k >= 0 ; i--,j--,k--)
	{
	  r[k]= (n1[i] + n2[j] + carry - 48 - 48) %10 + 48;
	  carry = (n1[i] + n2[j] + carry - 48 - 48) / 10 ;
	}
      if(l1 > l2)
	{
	  for(; i >= 0 && k >= 0; i--,k--)
	    {
	      r[k]= (n1[i] - 48 +carry) % 10 + 48;
	      carry = (n1[i] - 48+carry) / 10 ;
	    }
	}
      else
	{
	  for(;j >= 0 && k >= 0 ; j--,k--)
	    {
	      r[k]= (n2[j] - 48 + carry) %10 + 48;
	      carry = (n2[j] - 48 + carry) / 10 ;
	    }
	}
      r[0] = carry+48;
      if(r[0]=='0')
	shift_left(r);
      if(carry>0 && (l1 == size_r-1  || l2 == size_r-1))
	 return 0;
       else
	return r;
      }
  return 0;
}
