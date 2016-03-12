#include<stdio.h>
int print_char(char);
void print_string(char *,int);
void print_hex(int,int);
void get_hex(int, char *s);
int htoi(const char *s,int *p);
void print_buffer(char *b,int size)
{
  int i,j,n;
  char s[]="00";  
  i=0;
  for (i=0;i<size;i=i+10)
    {
      print_hex(i,0);
      print_char(':');

      for(j=0;j<10;j++)
	{
  	  if(j%2==0) print_char(' ');
	  print_hex((int)b[i+j],6  );
	}      
      print_char(' ');
      for(j=0;j<10;j++)
	{
	 get_hex((int)b[i+j],s);	 
	 htoi(s,&n);

	 if(n==96 || (n<39 && n!=35 && n!=32 ) )
	 print_char('.');
	 else
       print_char(n);
	}
      print_char('\n');
      
    }
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

  print_string(s,q);
}

void get_hex(int n, char *s)
{
  int r,i;

  char c[]="0123456789abcdef";

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


void print_string(char *str,int q)
{
  int i=0;

  while(*(str+i+q)!='\0')
    {
      print_char(*(str+i+q));
      i++;
    }
}

int htoi(const char *s, int  *result)
{
  if ((*s == '0') && (s[1] == 'x' || s[1] == 'X')) {
    s += 2;
  }
  for (*result = 0; *s; ++s) {
    int n = 0;
    if (*s >= 'a' && *s <= 'f') {
      n = *s - 'a' + 10;
    } else if (*s >= '0' && *s <= '9') {
      n = *s - '0';
    }

    *result *= 16;
    *result +=  n;
  }
  return 0;
}


                                                                                                                                                                                                                                                                                                                                        

