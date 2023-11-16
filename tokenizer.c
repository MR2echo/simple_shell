#include "shell.h"


char **tokenizer(char *line)
{
    char *token = NULL, *tmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;


    if(!line)
       return (NULL);
    tmp = _strdup(line);  
    token = strtok(tmp, DELIMITER);
    if (token == NULL)
    {
        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }

    while (token)
    {
        cpt++;
        token = strtok(NULL, DELIMITER);
    }
    free(tmp), tmp = NULL;

    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return(NULL);
    }

    token = strtok(line, DELIMITER);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELIMITER);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);
}
