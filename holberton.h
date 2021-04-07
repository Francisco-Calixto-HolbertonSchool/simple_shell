#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

extern char **environ;

/*protoypes*/
char **parser(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _putchar(char c);
void free_array(char **argv);
size_t _strcspn(char *s, char par);
char *_getenv(const char *name);
char **findpath(void);
char *_which(char *cmd);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
