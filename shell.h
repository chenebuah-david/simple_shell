#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_CMD_LENGTH 1024
#define MAX_PATHS 64
#define PATH_DELIM ":"
#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64
extern char **environ;
char *search_path(char *cmd, char *paths[], int npaths);
int _strcmp (char *s1, const char *s2);
char *_getline(char **line, size_t *n, FILE *ptr);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);
void exit_shell(char *args[]);
#endif
