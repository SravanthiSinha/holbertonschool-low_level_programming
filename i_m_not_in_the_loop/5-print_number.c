int print_char(char);
long power(unsigned long  x,int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}
int  get_len (unsigned long  value){
   int l=1;
   while(value>9)
    {
     l++;
     value/=10;
    }
  return l;
}
void my_print(unsigned long x){
  long result;
  int len,p;
  len=get_len(x);
  p=len;
  while(p<=len && x!=0)
    {
        result=x/power(10,p-1);
        print_char(result+48);
        x=x-(result*power(10,p-1));
        p--;
        len=get_len(x);
        while(p>len)
          {
            print_char(48);
            p--;
          }
    }
}
void print_number(int x)
{
  if (x==0)print_char(48);
  else if(x<0)
    {
    print_char(45);
    my_print((unsigned long)x*-1);
    }
  else{
    my_print(x);
  }
}
