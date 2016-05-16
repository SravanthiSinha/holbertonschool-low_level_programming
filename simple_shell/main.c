#include "libshell/libshell.h"
#include "utils/utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>

int exe_exists(char *s);
char *getcommand(char **env, char *cmd);
int exe_fork(char **env, char **argv);
int handlespl(char **args, int status,int pid);
void print_env(int pid);

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv, char **env)
{
  char *command;
  char **args;
  pid_t cpid;
  int status;
  
  status =0;
  while(1)
    {
      /*Display a prompt*/
       print_prompt("shellisfun$:");
       /*wait for you to write a command line */
       command = read_line(0);
       /*split the user input to find the command */
       args = string_split(command, ' ');
       
       if (handlespl(args,status,getpid()))
	 continue;

       /* create a process for the command to be executed*/
       if((cpid = fork()) == -1)
	 {
	   perror("fork error");
	   exit(EXIT_FAILURE);
	 }
       else if(cpid  == 0)
	 {	
	   /*return to the immediate parent once the command is executed*/
	   return exe_fork(env, args);
	 }
       else
	 {
	   wait(&status);
	 }
    }
  return (0);
}

void print_env(int pid)
{
  char *path;
  char str[100];
  
  int_str(pid,str);
  path = string_concat("/proc/",str);
  path = string_concat(path,"/environ");
  print_proccontent(path);
}
int handlespl( char **args, __attribute__((unused)) int status,int pid)
{
  /*Terminates your program*/
  if(str_ncomp(args[0], "exit", str_len("exit")) == 0)
    {
      exit(0);	        
    }
  if(str_ncomp(args[0], "env", str_len("env")) == 0)
    {
      print_env(pid);
      return 1;
    }
  else if((str_ncomp(args[0],"echo",str_len("echo")) == 0) && (str_ncomp(args[1],"$?",str_len("$?")) == 0))
    {
      print_number(status);
      print_prompt("\n");
      return 1;
    }
  else if((str_ncomp(args[0],"$?",str_len("$?")) == 0))
    {
      print_number(status);
      print_prompt(": command not found\n");
      return 1;
    }
  return 0;
}

/* execute the executables(those that can be
   found in the directories listed in the PATH environment variable)
   If an executable cannot be found,
   Display an error message and display the prompt again
*/
int exe_fork(char **env, char **args)
{
  char *path;
  int exe_status;

  exe_status =0;
  path ='\0';
  if(args[0][0] != '/')
    path = getcommand(env,args[0]);
  else
    path = args[0];
  exe_status = execve(path,args,env);
  if(exe_status == -1)
    {
      if(str_ncomp(args[0],"$?",str_len("$?")) != 0)
	{
	  print_prompt(args[0]);
	  print_prompt(": command not found\n");        
	}
    }
  return (exe_status);
}
 
/* get the path of the executable for the user command*/
char *getcommand(char **env , char *cmd)
{
  char **paths;
  char *path;
  int i;

  path = '\0';
  /*grab the path variable from env*/
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
  /* grab the executable path from the PATH variable*/
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

/* check the existence of the exectuable */
int exe_exists(char *s)
{
  struct stat fileStat;

  if(lstat(s, &fileStat) == -1) 
    {
      return (0);
    }
  else
    return(1);
}

