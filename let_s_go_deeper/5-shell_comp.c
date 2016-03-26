 int  match_strings(char *first, char * second)
 {

   if (*first == '\0' && *second == '\0')
     return 1;
 

   if (*second == '*' && *( second + 1 ) != '\0' && *first == '\0')
     return 0;

   if (*first == *second)
     return match_strings(first + 1, second + 1);
 
   if (*second == '*')
     return match_strings(first + 1, second) || match_strings(first, second + 1);

   return 0;
 }
 

int shell_comp(char *s1, char *s2)
{ 
  return match_strings(s1,s2)? 1: 0;
 }
 
