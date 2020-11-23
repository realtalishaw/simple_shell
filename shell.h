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

int shell_builtin(char **args, char *line);
void shell_run(char **args, char *line);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);


/* parser.c */

/*char **parser(char *string, char *delim);*/
char **parser(char *line);
void fork_exec(char *path, char **token, char **env);
char *com_remover(char *path);
int double_space_remover(char *path);
unsigned int _wordCount(char *str);
int _strlen(char *str);
int *_astrlen(char **str);
char *_strdup(char *source, unsigned int extra);
char **tokenizer(char *buffer);

/**
 * struct global - global variables (not bool flags)
 * @command: name of command that's been parsed
 * @command_length: length of command string
 * @line_no: line no.
 * @exit_status: number to exit with (error number)
 * @input: input number (file open)
 * @az: name of shell (argv[0])
 */
struct global
{
	char *command;
	int command_length;
	int line_no;
	int exit_status;
	int input;
	char *az;

} global;

extern char **environ;

#endif
