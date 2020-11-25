#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>
#define BUFSIZE 1024

int shell_builtin(char **args, char *line);
void shell_run(char **args, char *line);
int _strcmp(char *s1, char *s2);
typedef void sigfunc(int);
void sig_handler(int signo);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_searchpath(char *command, char *fullpath, char *path);
char *_getenv(char *name);
char **parser(char *line);
void fork_exec(char *path, char **token, char **env);
char *com_remover(char *path);
int double_space_remover(char *path);
unsigned int _wordCount(char *str);
int _strlen(char *str);
int *_astrlen(char **str);
char *_strdup(char *source, unsigned int extra);
char **tokenizer(char *buffer);

extern char **environ;
#endif
