#include "libshell/libshell.h"
#include "utils/utils.h"

int exe_exists(char *s);
char *getcommand(char **env, char *cmd);
int exe_fork(char **env, char **argv);
int handlebuiltins(char **args, int status,int pid);

int main(int c,__attribute__((unused))char **v, char **env)
/* Launches shell */
{
	char *command;
	char **args;
	pid_t cpid;
	int status;
	int exe_status;
	exe_status = 0;
	status = 0;
	(void)(c);
	while(1){
		print_prompt("shellisfun$:");
		command = read_line(0);
		if(str_len(command) > 0){
			args = string_split(command,' ');
			free(command);
			if (handlebuiltins(args,status,getpid()))
				continue;
			if((cpid = fork()) == -1);
			else if(cpid  == 0){
				exe_status = exe_fork(env,args);
				free_split(args);
				return exe_status;
			}
			else
				wait(&status);
			free_split(args);
		}
	}
	return status;
}

int handlebuiltins( char **args, __attribute__((unused)) int status,int pid)
  /* Handle Builtins */
{
	if(str_ncomp(args[0],"exit",str_len("exit")) == 0){
		free_split(args);
		exit(status);
	}
	if(str_ncomp(args[0],"env",str_len("env")) == 0){
		free_split(args);
		print_env(pid);
		return 1;
	}
	else if((str_ncomp(args[0],"echo",str_len("echo")) == 0)){
	        if((str_ncomp(args[1],"$?",str_len("$?")) == 0)){
		         free_split(args);
			 print_number(status);
			 print_prompt("\n");
			 return 1;
		 }
	}
	else if((str_ncomp(args[0],"$?",str_len("$?")) == 0)){
		free_split(args);
		print_number(status);
		print_prompt(": command not found\n");
		return 1;
	}
	return 0;
}

int exe_fork(char **env, char **args)
/* execute the executables(those that can be
 * found in the directories listed in the PATH environment variable)
 * If an executable cannot be found,
 * Display an error message and display the prompt again
 */
{
	char *path;
	int exe_status;
	exe_status = -1;
	if(args[0][0] != '/')
	  path = getcommand(env,args[0]);
	else
	  path = string_dup(args[0]);
	if(path!='\0')
	  exe_status = execve(path,args,env);
	if(exe_status == -1){
		if(str_ncomp(args[0],"$?",str_len("$?")) != 0){
			print_prompt(args[0]);
			print_prompt(": command not found\n");
		}
	}
	return exe_status;
}


char *getcommand(char **env , char *cmd)
/* gets the path of the executable for the user command*/
{
	char **paths;
	char *path;
	int i;
	char *pathslash;
	/*grab the path variable from env*/
	for ( i = 0 ; env[i]!= NULL; ++i){
		if(str_ncomp(env[i],"PATH=",str_len("PATH=")) == 0){
			paths = string_split(env[i],'=');
			path = string_dup(paths[1]);
			free_split(paths);
			paths = string_split(path, ':');
			free(path);
			break;
		}
	}
	/* grab the executable path from the PATH variable*/
	for(i = 0; paths[i] != NULL; i++){
		pathslash = string_concat(paths[i],"/");
		path = string_concat(pathslash,cmd);
		free(pathslash);
		if(exe_exists(path)){
			free_split(paths);
			return path;
		}
		free(path);
	}
	free_split(paths);
	return '\0';
}


int exe_exists(char *s)
/* check the existence of the exectuable */  
{
	struct stat fileStat;

	if(lstat(s,&fileStat) == -1)
	        return 0;
	else
	        return 1;
}
