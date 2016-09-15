void rev_list(List **head)
{
  List *curr;
  List *prev;
  List *nxt;

  prev = NULL;
  curr = *head;
  while(curr!=NULL)
    {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
      *head = prev ;
}
