#include <stdio.h>
int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int a, int b){
  int i;

  char options[5] = { '+', '-', '*','/', '%'};

  int (*op_func[5])(int, int) = {op_add, op_sub, op_mul, op_div, op_mod};

  for(i = 0;i < 5; i++)
    {
      if(c == options[i])
	{
	  return op_func[i];
	}
    }

    return NULL;
}
