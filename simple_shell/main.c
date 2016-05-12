#include "libshell/libshell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int str_len(const char *s)
{
  int i;
  
  i = 0;
  while(s[i])
    {
      i++;
    }  
  return (i);  
}

int strings_compare(char *s1, char *s2)
{
  int i,n1,n2,t,n;

  i = 0;
  t = 0;  
  n1=str_len(s1);
  n2=str_len(s2);
  
  n=(n1>=n2)?n1:n2;

  while(i<n)
    {
      if(s1[i]!=s2[i])
	{
	  t=s1[i]-s2[i];
	  break;
	}
      else{
	t=0;
      }
      i++;
    }

  return (t);

}

void print_prompt(char *s)
{
  write(1,s,str_len(s));
}

int main(int argc, char **argv, char **env)
{
  char *command;
  char **args;
  pid_t pid;
  int status;
  while(1)
    {
      if( (pid = fork()) == -1)
	{
	}
      if(pid  == 0)
	{
  	      print_prompt("cisfun$:");
 	      command = read_line(0);
	      args = string_split(command, ' ');
	      if(strings_compare(args[0],"exit") == 0)
		exit(0);
	      execve(args[0],args,env);      
	}
      else
	{
	  wait(&status);
	}

    }    
  return (0);
}

