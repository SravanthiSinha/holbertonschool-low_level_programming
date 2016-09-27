#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include <stdio.h>


void print_queue_c(Queue *q)
{

  if(q == NULL)
    return;
  printf(", %s",q->str);
  print_queue_c(q->next);
}

void print_queue(Queue *q)
{
  if(q == NULL)
    return;
  else{
    printf("%s",q->str);
    print_queue_c(q->next);
  }
  printf("\n");
}
