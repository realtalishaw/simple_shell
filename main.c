#include "shell.h"

int main(void) {
  char *line = NULL;
  char **args;
  size_t size = 0;
  int status;

  do {
    putchar('$');
    putchar(' ');
    getline(&line, &size, stdin);
    if (line[0] == '\n')
    {
      continue;
    }
    /*printf("got line!\n");*/
    args = tokenizer(line);
    /*printf("got args!\n");*/
    status = shell_builtin(args, line);

    free(line);
    free(args);
  } while (1);


  return (0);
}


/**
 * _strcat - gkjsgkjw;
 * @dest: kfdjkla
 * @src: fdjkkfjal
 *
 * Return: lkjdalk;f
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int len;

	for (len = 0; dest[len] != 0;)
	{
		len++;
	}

	for (i = 0; src[i] != 0; i++)
		dest[len + i] = src[i];
	return (dest);
}
