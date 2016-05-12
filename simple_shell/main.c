#include "libshell/libshell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

char *string_concat(char * dest,char *src);
int str_len(const char *s);
int str_ncomp( char *s1, char*s2, int k);
void print_prompt(char *s);
int exe_exists(char *s);
char *getcommand(char **env, char *cmd);
void print_number(int);
int print_char(char);

int main(int argc, char **argv, char **env)
{
  char *command;
  char **args;
  pid_t pid;
  int status;
  char *path;
  int i;
  int exefound;

  i = 0;
  exefound = 0;
  path ='\0';
  while(1)
    {
       print_prompt("shellisfun$:");
       command = read_line(0);
       args = string_split(command, ' ');
       if(str_ncomp(args[0], "exit", str_len("exit")) == 0)
	    exit(0);	 
       
       if((pid = fork()) == -1);
       else if(pid  == 0)
	 {	
	   if(str_ncomp(args[0], "$?", str_len("$?")) == 0)
	     {
	       print_number(status);
	       print_prompt("\n");
	       return (0);
	     }
	   else if(args[0][0] != '/')
	     path = getcommand(env,args[0]);
	   else
	     path = args[0];
	   if(execve(path,args,env) == -1)
	     {
	       print_prompt("shellisfun$:");
	       print_prompt(args[0]);
	       print_prompt(": command not found\n");	       	 
	       return (0);
	      }
	   return (0);
	 }
       else
	 {
	   wait(&status);
	 }
    }    
  return (0);
}

char *getcommand(char **env , char *cmd)
{
  char **paths;
  char *path;
  int i;

  path = '\0';
    for ( i = 0 ; env[i]!= NULL;++i)
    {
      if(str_ncomp(env[i], "PATH=", str_len("PATH=")) == 0)
	{
	  paths = string_split(env[i],'=');
	  path = paths[1];
	  paths = string_split(path, ':');
	  break;
	}	  
    }
    for(i = 0; paths[i] != NULL;i++)
     {
       path = string_concat(string_concat(paths[i],"/"),cmd);
       if(exe_exists(path))
	 {
	   return path;
	 }
       path = '\0';
     }	
     return path;
}

int exe_exists(char *s)
{
  struct stat fileStat;
  if (lstat(s, &fileStat) == -1) 
    {
      return (0);
    }
  else
    return(1);
}

void print_number(int n)
{
  if ( n > 10 )
    print_number(n /10);
  print_char(n % 10 +48);  
}

int print_char(char c)
{
  write(1,&c,1);
}
/*
 *  a function that concatenates two strings.
 */
char *string_concat(char *s1, char *s2)
{
 
  int len,len2,i,j;
  char *s;

  i = 0;
  j=0;
  len = str_len(s1);
  len2= str_len(s2);  
  s = malloc(sizeof(*s) * (len + len2 + 1) );
  

  if (s == NULL)
    {
      return ( NULL);
    }
  else
    {
      while(i < len)
	{
	  s[i]= s1[i];
	  i++;
	}

      while(j < len2)
	{
	  s[i] = s2[j];
	  i++;
	  j++;
	}
      s[i] = '\0';
    }
  return s; 
  
}
  

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

int str_ncomp(char *s1, char *s2, int k)
{
  int i,n1,n2,t,n;

  i = 0;
  t = 0;  
  n1=str_len(s1);
  n2=str_len(s2);
  
  n = (n1 >= n2) ? n1 : n2;
  n = (k > n) ? n : k;
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



