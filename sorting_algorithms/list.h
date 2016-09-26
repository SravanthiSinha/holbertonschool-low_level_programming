#ifndef _LIST_H_
#define _LIST_H_

typedef struct List {
  /*
   * The following element of the struct
   * might be named differently during the correction
   */
  char *str;
  /*
   * The 'next' element will always be present in the struct
   */
  struct List *next;
} List;

#endif
