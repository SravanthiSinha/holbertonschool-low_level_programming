#include <stdio.h>
#include <stdlib.h>

int (*get_op_func(char c))(int, int);

int main(int argc, char **argv){
  int (*a)(int,int);
  
  if (argc != 4 )
    return 1;
  
  a = get_op_func(*argv[2]);   
  if( *a == NULL)
    return 1;

  printf("%d\n", (*a)(atoi(argv[1]), atoi(argv[3])));
  return 0;
}
