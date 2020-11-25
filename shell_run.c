#include "shell.h"
/**
 * shell_run - does things
 * @args: args
 * @line: line
 * Return: 0
 */
void shell_run(char **args, __attribute__((unused))char *line)
{
pid_t pid, pid2;
int status;
char *path;
char *fullpath;
fullpath = NULL;
path = _getenv("PATH");

fullpath = _searchpath(args[0], fullpath, path);
pid = fork();
if (pid == 0)
{
if (execve(fullpath, args, environ) == -1)
perror("shell");
free(fullpath);
exit(0);
}
else if (pid < 0)
perror("shell2");
else
{
do {
	pid2 = waitpid(pid, &status, WUNTRACED), kill(pid2, SIGKILL);
	free(fullpath);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}
