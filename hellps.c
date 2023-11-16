#include "shell.h"

void freeArrayOfHellps(char **arr)
{
    int i;
    if (!arr)
        return;

    for (i = 0; arr[i]; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr), arr = NULL;
}


void printerror(char *name, char *cmd, int ind)
{
    char *index, mssg[] = ": not found\n";
    index = itoa(ind); 

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, " :", 2);
    write(STDERR_FILENO, index,  -strlen(index));
    write(STDERR_FILENO, " :", 2);
    write(STDERR_FILENO, cmd,  -strlen(cmd));
    write(STDERR_FILENO, mssg,  -strlen(mssg));

    free(index);
}



char *itoa(int n)
{
   char buffer[20];
   int i = 0;

   if (n == 0)
       buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    reverse_string(buffer, i);

    return (_strdup(buffer));   
}





void reverse_string(char *str, int leng)
{
   char tmp;
   int start = 0;
   int end = leng -1;


   while (start < end)
   {
      tmp = str[start];
      str[start] = str[end];
      str[end] = tmp;
      start++;
      end--;
   }   
}