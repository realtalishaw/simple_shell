#include "shell.h"
void shell_run(char **args, char *line)
{
pid_t pid, pid2;
int status;
int i;
char parmList[1024] = "/bin/";
char *newParm;
char usr[1024] = "/usr";
char *path;
char* usrcmd[19];


usrcmd[0] = "clear";
usrcmd[1] = "touch";
usrcmd[2] = "find";
usrcmd[3] = "du";
usrcmd[4] = "head";
usrcmd[5] = "tail";
usrcmd[6] = "diff";
usrcmd[7] = "wget";
usrcmd[8] = "top";
usrcmd[9] = "man";
usrcmd[10] = "zip";
usrcmd[11] = "unzip";
usrcmd[12] = "curl";
usrcmd[13] = "diff";
usrcmd[14] = "free";
usrcmd[15] = "groups";
usrcmd[16] = "passwd";
usrcmd[17] = "env";
usrcmd[18] = NULL;


for (i = 0; i < 19; i++)
{
  /*if (args[0][i] == '/')
  {
    path = *args;
    break;
  }*/
  if (_strcmp(args[0], usrcmd[i]) == 0)
  {
   newParm = _strcat(usr, parmList);
    path = _strcat(newParm, args[0]);
    break;
  }
  else if (i == 18)
  {
    path = _strcat(parmList, args[0]);
  }
}


 
pid = fork();
if (pid == 0)
{
  if (execve(path, args, environ) == -1){
    perror("shell");

  }
  exit(0);
} else if (pid < 0) {
  perror("shell2");
} else {
  do {
    pid2 = waitpid(pid, &status, WUNTRACED);
    free(line);
    line = NULL;
    free(args);
    args = NULL;
    kill(pid2, SIGKILL);
  } while (!WIFEXITED(status) && ! WIFSIGNALED(status));
}
}
