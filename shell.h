#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

/* Incase using getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

/* convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* read or write buffers */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define HIST_MAX	4096
#define HIST_FILE	".simple_shell_history"


extern char **environ;


/**
 * struct liststr - singly linked list
 * @str: a particular string
 * @next: it points to the following/next node
 * @num: number field
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 *struct passinfo - This contains pseudo-arguments to include in a function,
 *		allowing the same prototype for function pointer struct
 *@line_count: it counts the error
 *@path: a path for the string for the recent command
 *@arg: a string that is generated from getline with arguments
 *@argv: an array of strings generated from arguments
 *@argc: the argument count
 *@alias: the node of alias
 *@environ: upgraded copy of environ from LL env
 *@env: A linked list of a local copy of environ
 *@fname: The file name of the program
 *@linecount_flag: This counts the line of input
 *@err_num: The error code
 *@history: The node of history
 *@histcount: The history line number to count
 *@cmd_buf: The address of the pointer to cmd_buf
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: tThe fd from which to read the line input
 *@status: The return of status of the last executed command
 *@env_changed: It is on if the environ was changed
 */

typedef struct passinfo
{
	unsigned int line_count;
	char *path;
	char *arg;
	char **argv;
	int argc;
	list_t *alias;
	char **environ;
	list_t *env;
	char *fname;
	int linecount_flag;
	int err_num;
	list_t *history;
	int histcount;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int status;
	int env_changed;

} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */

typedef struct builtin

{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* errors_0.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* reallocate.c */
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors_1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin_0.c */
int _mycd(info_t *info);
int _myhelp(info_t *info);
int _myexit(info_t *info);

/* builtin_1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/* get_line.c */
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);

/* get_info.c */
void free_info(info_t *, int);
void clear_info(info_t *);
void set_info(info_t *, char **);

/* env.c */
int _mysetenv(info_t *);
int populate_env_list(info_t *);
int _myunsetenv(info_t *);
int _myenv(info_t *);
char *_getenv(info_t *, const char *);

/* get_env.c */
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);
char **get_environ(info_t *);

/* hist.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* lists_0.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists_1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
