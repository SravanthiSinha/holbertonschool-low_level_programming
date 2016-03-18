#include<stdio.h>
int print_char(char);
void print_hex(int,int);
void get_hex(int, char *s);
unsigned int htoi(char s[]);

void print_space(int j)
{
      while(j<10)
	{
	  print_char(' ');
	  print_char(' ');
	  if(j%2==0)
	    print_char(' ');
	  j++;
	}
      print_char(' ');
}

void print_buffer(char *b,int size)
{
  int i=0,j=0,k=0,l=0; unsigned int n;
  char s[]="00";  
  for (i=0;i<size;i=i+10)
    {
      print_hex(i,0);
      print_char(':');
      for(j=0;j<10 && k< size;j++,k++)
	{
	  if(j%2==0)print_char(' ');
	  print_hex((int)b[i+j],6  );
	}      
      print_space(j);
      for(j=0;j<10 && l< size;j++,l++)
	{
	  get_hex((int)b[i+j],s); 
	  n=htoi(s);
	  n<31?print_char('.'):print_char(n);  
	}
      print_char('\n');     
    }
  if(size<0)print_char('\n');
}

void print_hex(int n,int q)
{
  int r,i;

  char c[]="0123456789abcdef";
  char s[]  ="00000000";
  i=7;
  while(n>16)
    {
      r=n%16;
      s[i]=(c[r]);
      i--;
      n=n/16;
    }
  s[i]=c[n];

  i=0;

  while(*(s+i+q)!='\0')
    {
      print_char(*(s+i+q));
      i++;
    }
}

void get_hex(int n, char *s)
{
  int r,i;

  char c[]="0123456789abcdef";
  s[0]='0';
  s[1]='0';
  i=1;
  while(n>16)
    {
      r=n%16;
      s[i]=c[r];
      i--;
      n=n/16;
    }
  s[i]=c[n];
}

unsigned int htoi(char s[])
{
  unsigned int val = 0;
  int x = 0;
     
  if(s[x] == '0' && (s[x+1]=='x' || s[x+1]=='X')) x+=2;
     
  while(s[x]!='\0')
    {
      if(s[x] >= '0' && s[x] <='9')
          val = val * 16 + s[x] - '0';
      else if(s[x]>='A' && s[x] <='F')
          val = val * 16 + s[x] - 'A' + 10;
      else if(s[x]>='a' && s[x] <='f')
          val = val * 16 + s[x] - 'a' + 10;
      else return 0;
      x++;
    }
  return val;
}

