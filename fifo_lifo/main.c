#include <stdlib.h>
#include "queue.h"

/* The function 'print_queue' is provided */
void print_queue(const Queue *);

int push_queue(Queue **, char *);

int main(int ac, char **av)
{
  Queue *queue;
  int i;

  queue = NULL;
  i = 0;
  while (i < ac)
    {
      push_queue(&queue, av[i]);
      ++i;
    }
  print_queue(queue);
  return (0);
}
