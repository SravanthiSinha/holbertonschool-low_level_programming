#include <stdio.h>
int main()
{
unsigned long a=2880067194370816120;
unsigned long  b=4660046610375530309;
unsigned long c,d;
  c=a/1000000000000+b/1000000000000;
  d=a%1000000000000+b%1000000000000; 
  
  
if(d>10000000000000)c++;
  printf("%lu%lu\n",c,d);  
      a=b/1000000000000;
      b=b%1000000000000;
  printf("%lu%lu\n",a+c,b+d); 
  printf("%lu%lu\n",a+2*(c),b+2*(d)); 
  printf("%lu%lu\n",2*(a)+3*(c),2*(b)+3*(d));
  printf("%lu%lu\n",3*(a)+5*(c),3*(b)+5*(d)); 
  printf("%lu%lu\n",5*(a)+8*(c),5*(b)+8*(d)); 
  printf("%lu%lu\n",8*(a)+13*(c),8*(b)+13*(d));  


  

  return(0);
}
