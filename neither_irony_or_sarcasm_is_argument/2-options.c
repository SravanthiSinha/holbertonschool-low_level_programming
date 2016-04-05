#include <stdio.h>
#include<string.h>



int main(int argc, char *argv[])
{
  int i;
  unsigned int l,m;
char options[1000];
 char c[4];
 char *s;
 strcpy( options,"0");

  for(i=1;i<argc;i++)
    {
      if(strcmp(argv[i],"--")==0)
	{
	  break;
	}
      else if(argv[i][0]=='-' && argv[i][1]=='-')  
	{
	  s=argv[i];
	  s +=2;	 
	  if(!strstr(options,s))
	    {  
	      strcat(options,s);
	      strcat(options,", ");
	    }
	}
      else if(argv[i][0]=='-')
	{
	  s=argv[i];
	  s +=1;
	  m=strlen(s);
	  l=1;
	  while(l<=m)
	    {
	      c[0]=argv[i][l];
	      c[1]=',';
	      c[2]=' ';
	      c[3]='\0';
	      if(!strstr(options,c))
		{
		  strcat(options,c);
		}
	      l++;
	      }
	}

	}

  options[strlen(options)-2]='\0';
  printf("%.*s\n",(int)strlen(options),options+1);

  return 0;
}
