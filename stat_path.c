#include "shell.h"

char *_getStatPath(char *cmd)
{
    char *path_env, **full_command, *dir;
    int i;
    strcat stat st;

    for (i = 0; cmd[i]; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &st) == 0)
                return (_strdup(cmd));

            return (NULL);
        }
    }

    path_env = _getenviron("PATH");
    if (!path_env)
        return (NULL);

    dir = strtok(path_env, ":");
    while (dir)
    {
        /* size = len(directory) + len(command) + 2 ('/' and '\0') */
        full_command = malloc(_strlen(dir) + _strlen(cmd) + 2);

        if (full_command)
        {
            _strcpy(full_command, dir);
            _strcat(full_command, "/");
            _strcat(full_command, cmd);

            if (stat(full_command, &st) == 0)
            {
                free(path_env);
                return (full_command);
            }
            free(full_command), full_command = NULL;

            dir = strtok(NULL, ":");
        }
    }

    free(path_env);
    return (NULL);
}


