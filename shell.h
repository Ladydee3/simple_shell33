#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* If im using system getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

#define LIST_MAX
#define LIST_FILE

/*READ/WRITE BUFFERS */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024

/* CONVERT_NUMBERS() */
#define CONVERT_UNSIGNED
#define CONVERT_LOWERCASE

/* COMMAND CHAINING */
#define CMD_AND
#define CMD_OR
#define CMD_NORM
#define CHAIN

extern char **environ;

/**
 * struct liststr - singly list link
 * @num: field number
 * @str: string
 * @next: next node pointed
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - pseudo-arguments to pass into function,
 *                  allowing uniform prototype for function pointer
 * @readfd: fd from which read line input
 * @histcount: line number count inthe history
 * @status: the last exec'd command return stsatus
 * @cmd_buf: pointer address to cmc_buf, if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @env: copy of linked list localof environ
 * @environ: modify custom copy of environ from LL env
 * @env_changed: if environ changed on
 * @history: node history
 * @alias: alias node
 * @arg: string containing arguments generated from getline
 * @argv: string array generated from arg
 * @linecount_flag: this line input if on count
 * @line_count: count error
 * @err_num: code error for exit()s
 * @fname:filename for program
 * @path: current commantstring path
 * @argc: arugument count
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;
/**
 * struct builtin - builtin string and relared function contained
 * @type: builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* my_parser.c */
int is_cmd(info_t *, char *);
char *map_char(char *, int, int);
char *find_path(info_t *, char *, char *);

/* my_errors.c */
int _putfd(char c, int fd);
void _eputs(char *);
int _putsfd(char *str, int fd);
int _eputchar(char);

/* loophsh.c */
int loophsh(char **);

/* my_shloop.c */
void finf_cmd(info_t *);
int hsh(info_t *, char **);
int find_buitin(info_t *);
void fork_cmd(info_t *);

/* my_atoi.c */
int _atoi(char *);
int is_delim(char, char *);
int _isalpha(int);
int interactive(info_t *);

/* my_string.c */
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *begin_with(const char *, const char *);

/* my_builtin.c */
int _mycd(info_t *);
int _myexit(info_t *);
int _myhelp(info_t *);

/* my_realloc.c */
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* my_string1.c */
int _putchar(char);
char *_strcpy(char *, char *);
void _puts(char *);
char *_strmap(const char *);

/* my_tokenizer.c */
char **strtow(char *, char *);
char **strtow22(char *, char);

/* my_exits.c */
char *_strncat(char *, char*, int);
char *_strncpy(char *, char*, int);
char *_strchr(char *, char);

/* my_memory.c */
int bfree(void **);

/* my_history.c */
int build_history_list(info_t *info, char *buf, int linecount);
int write_history(info_t *info);
int renumber_history(info_t *info);
int read_history(info_t *info);
char *get_history_file(info_t *info);

/* my_getinfo.c */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* my_getline.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
void signHandler(int);

/* my_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* my_errors1.c */
void print_error(info_t *, char *);
int _erratoi(char *);
char *convert_number(long int, int, int);
void remove_comments(char *);
int print_d(int, int);

/* my_vars.c */
int replace_vars(info_t *);
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t);
int replace_alias(info_t *);

/* my_getenv */
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);

/* my_list1.c */
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
list_t *node_begin_with(list_t *, char *, char);
size_t list_len(const list_t *);
char **list_to_string(list_t *);

/* my_list.c */
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_t_str(const list_t *);
list_t *add_node(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* my_environ.c */
int myunsetenv(info_t *);
int myenv(info_t *);
char *_getenv(info_t *, const char *);
int mysetenv(info_t *);
int populate_env_list(info_t *);

#endif
