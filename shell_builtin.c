#include "shell.h"
int shell_builtin(char **args, char *line)
{
    int i, switchOwnArg = 0; 
    char* builtin[6]; 
  
    builtin[0] = "";
    builtin[1] = "exit"; 
    builtin[2] = "cd"; 
    builtin[3] = "help";
    builtin[4] = "inspire"; 
    builtin[5] = "alias";

  for (i = 0; i < 6; i++)
  {

    if (_strcmp(args[0], builtin[i]) == 0)
        {
          switchOwnArg += i;
          /*printf("Builtin: %d\n", switchOwnArg);*/
          break;
        }
  }
  

    switch (switchOwnArg) { 
    case 1:  
     /*  
        free(args);
        free(line);*/
        exit(0);
    case 2: 
        chdir(args[1]); 
        return 1; 
    case 3: 
       /* printf("Will help you eventually\n");*/
        return 1; 
    case 4: 
       /* printf("You got this!\n"); */
        return 1; 
    case 5:
     /* printf("Alias will happen here... maybe\n");*/
      return 1;
    default: 
      shell_run (args, line); 
      return 0;
    }
    return 0; 
}
