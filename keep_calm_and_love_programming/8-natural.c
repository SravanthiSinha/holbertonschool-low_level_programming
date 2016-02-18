
#include <stdio.h>

int main(void){
  int n,i;
  int sum;

  n=1024;
  sum=0;
  for(i=1;i<n;i++)
    {
      if(i%3==0 || i%5==0)
	sum=sum+i;
    }
  printf("%i",sum);
    

  
  return 0;
}
