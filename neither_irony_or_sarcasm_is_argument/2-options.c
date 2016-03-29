#include <stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int i;

  for(i=1;i<argc;i++)
    {
      if(argv[i][0]=='-' && argv[i][1]=='-' && argv[i][2]=='\0')  
	{
	  i=i+2;
	}
      else if(argv[i][0]=='-' && argv[i][1]=='-')  
	{
	printf("%.*s\n",(int)strlen(argv[i]),argv[i]+2);
	i++;
	}
      else if(argv[i][0]=='-')
	printf("%.*s\n",(int)strlen(argv[i]),argv[i]+1);
    }
  
  return 0;
}
