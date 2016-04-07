/*
* A function that executes a function given as 
* a parameter on each element of an array
*/

void array_iterator(int *array, int size, void (*action_func)(int)){
  int i;

  for(i = 0; i < size; i++)
    (*action_func)(array[i]);
}
