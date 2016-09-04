#include<stdio.h>
#define n 98

int main(void){
  int f1_l,f2_l,f3_l,f1_c,f2_c,f3_c,f1_r,f2_r,f3_r,carry,carry2;
  int no = n;
  f1_l = 0;
  f1_c = 0;
  f1_r = 0;
  f2_l = 0;
  f2_c = 0;
  f2_r = 1;
  f3_l = 0;
  f3_c = 0;
  f3_r = 1;
  while(no--)
    {
      carry = (f1_r + f2_r) / 100000000;
      f3_r = (f1_r + f2_r) % 100000000;
      f3_c = f1_c + f2_c +carry;            
      if(f3_c > 0)
	{
	  carry2 = (f1_c + f2_c + carry) / 100000000;
	  f3_c = (f1_c + f2_c +carry) % 100000000;
	  f3_l = f1_l + f2_l +carry2;
	  if(f3_l > 0)
	      printf("%d%0*d%0*d",f3_l,8,f3_c,8,f3_r);
	  else
	    printf("%d%0*d",f3_c,8,f3_r);
	}
      else
	  printf("%d",f3_r);
      if(no > 0)
	printf(", ");
      f1_r = f2_r;
      f2_r = f3_r;
      f1_c = f2_c;
      f2_c = f3_c;
      f1_l = f2_l;
      f2_l = f3_l;
    }
  printf("\n");
  return 0;
}
