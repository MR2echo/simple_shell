#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



#define DELIMITER " \t\n"
extern char **environ;


char *read_command(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv, int ind);
char *_getenviron(char *var);
char *_getStatPath(char *cmd);


char *_strdup(const char *str);
int _strcmp(char *t1, char * t2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);


void freeArrayOfHellps(char **arr);
void printerror(char *name, char *cmd, int ind);
char *itoa(int n);
void reverse_string(char *str, int leng);


#endif
