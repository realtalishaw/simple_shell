#include "shell.h"

int main(void) {
  char *line;
  char **args;
  /*int i;*/
  size_t size = 0;
  
 line = NULL;

  do {
    putchar('$');
    putchar(' ');
   
    getline(&line, &size, stdin);
    if (line[0] == '\n')
    {
      continue;
    }
    args = tokenizer(line);    

    shell_builtin(args, line);
      if (line != NULL)
      {
        free(line);
        line = NULL;
      }
      /*free(args);*/
      args = NULL;
  } while (1);


  return (0);
}
