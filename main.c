#include "shell.h"

/**
 * 
 * main -- Simple shell main function
 * @ac: count of argguments
 * @av: arguments
 * 
 * 
 * 
 * Return: 0 Always (success).
 */

int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0, ind = 0;
    (void) ac;



    while (1)
    {
        line = read_command();
        if (line == NULL)  /* reache EDF ctr + D */
        {
            if (isatty(STDIN_FILENO))
                    write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        ind++;
        
        
        command = tokenizer(line);
        if (!command)
            continue;

  

        status = _execute(command, argv, ind); 
    }
}
