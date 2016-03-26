int str_len(char *str)
{
  int len;

  len=0;
  while( *(str+len) != '\0' )
    len++;
  return len;
}

int checkpalindrome(char *s, int len, int count)
{
  if(count >= len) return 1;
  if(s[count] != s[len-count-1]) return 0;
  return checkpalindrome(s,len,count+1);
}  


int is_palindrome(char *s)
{  
  int len;
  
  len=str_len(s);

  return checkpalindrome(s,len,0);
}
