#ifndef PHICS_H
#define PHICS_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
char *find_file_in_path(char *filename, char *filepath);
extern char **environ;
void do_pid(pid_t pid, char *cmd, char *fullpath, char *args[], char **env);
int _strncmp(const char *s1, char *s2, size_t n);
size_t _strlen(const char *s);
int handle_cmd(char **args, char *argv, char *cmd);
int set(char *name, char *value);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
char *_strcpy(char *s1, char *s2);
ssize_t _getline(char **ptr, size_t *n, FILE *stm);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char *_strdup(char *str);
int cd_dir(char *name, char *argv);
#endif
