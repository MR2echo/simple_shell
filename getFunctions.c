#include "shell.h"


char *_strdup(const char *str)
{
    char *ptr;
    int i, count = 0;

    if (str == NULL)
         return (NULL);
    
    while (str[count])
          count++;
     
    ptr = malloc(sizeof(char) * (count + 1));
    if ( ptr == NULL)
         return (NULL);
    for (i = 0; i <= count; i++)
        ptr[i] = str[i];
    return (ptr);          
}



int _strcmp(char *t1, char * t2)
{
   int cmp;

   cmp = (int)*t1 - (int)*t2;
   while (*t1)
   {
      if (*t1 != *t2)
          break;
      t1++;
      t2++;
      cmp = (int)*t1 - (int)*t2;    
   }

   return (cmp);
}


int _strlen(char *s)
{
    int le = 0;

    while (s[le])
        le++;
    return (le);    
}



char *_strcat(char *dest, char *src)
{
    char *p = dest;

    while (*p)
        p++;

    while (*src)
    {
       *p = *src;
       p++;
       src++;      
    }    
    *p = '\0';
    return (dest);
}




char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
