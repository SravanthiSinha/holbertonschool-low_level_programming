void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {402, 94111, 98, 12, 1024};

  print_array(array, 5);
  quick_sort(array, 5);
  print_array(array, 5);
  return (0);
}
