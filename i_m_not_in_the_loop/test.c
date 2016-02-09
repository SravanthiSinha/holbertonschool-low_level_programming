int get_len (unsigned long  value){
  int l=1;
  while(value>9)
    {
      l++;
      value/=10;
    }
  return l;
}
int main (void)
{
  int x=789;
  int i=0;
  char s[10];
itoa(x,s,10);
  for(i=0;i< get_len(x);i++)
    print_char(s[i]+48);
  return 0;
}
