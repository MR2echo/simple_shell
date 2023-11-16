#include "shell.h"


int _execute(char **command, char **argv, int ind)
{
    char *full_command;
    pid_t child;
    int stat;


     full_command = _getStatPath(command[0]);
     if (!full_command)
     {
        printerror(argv[0], command[0], ind);
        freeArrayOfHellps(command);
        return(127);
     }

    child = fork();
    if (child == 0)
    {
        if (execve(full_command, command, environ) == -1)
        {  
            free(full_command), full_command = NULL;
            freeArrayOfHellps(command); 
        }
    }
    else
    {
        waitpid(child, &stat, 0);
        freeArrayOfHellps(command);
        free(full_command), full_command = NULL;
    }

    return(WEXITSTATUS(stat));
}
