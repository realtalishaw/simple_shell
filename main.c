#include "shell.h"

int main(void) {
  char *line = NULL;
  char **args;
  size_t size = 0;
  int c;
  /*int status;*/

  do {
    if (isatty(STDIN_FILENO) == 1)
    {
putchar('$');

    }
    c = getline(&line, &size, stdin);
    if (c == -1)
    {
exit (0);
    }
    if (line[0] == '\n')
    {
      continue;
    }
    /*printf("got line!\n");*/
    args = tokenizer(line);
    /*printf("got args!\n");*/
     shell_builtin(args, line);

    free(line);
    size = 0;
    free(args);
  } while (1);


  return (0);
}



