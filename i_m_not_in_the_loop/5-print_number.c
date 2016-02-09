int print_char(char);
int power(int  x,unsigned int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);

}
int  get_len (int  value){
   int l=1;
  while(value>9){
    l++; 
    value/=10;
  }
  return l;
}
void my_print(int x){
  int result=0;
  int len=0;
  int p=0;
  len=get_len(x);
  p=len;
  if (x==0)print_char(48);
  else{
    while(p<=len && x!=0)
      {
	result=x/power(10,p-1);
	print_char(result+48);
	x=x-(result*power(10,p-1));
	p--;
	len=get_len(x);
	while(p>len){
	  print_char(48);
	  p--;
	}
      }
  }
}
void print_number(int x)
{
  if (x==0)print_char(48);
  else if(x<0){
    print_char(45);
    my_print(x*-1);
  }
  else{
    my_print(x);
  }
}
