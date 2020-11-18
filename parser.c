#include "shell.h"

/**
 * parser - parses a single string in to strings inside a string
 * @string: incoming string
 * @delim: delimiter to parse string with
 * Return: returns a double pointer containing tokens
 */

/*char **parser(char *string, char *delim)
{
	unsigned int wrdCnt, index;
	char **tokened, *token **envc;

	string = com_remover(string);
	envc = environ;

	wrdCnt = _wordCount(string);
	tokened = malloc((wrdCnt + 1) * sizeof(char *));
	malloced 
	if (!tokened)
	{
		basic_err();
		perror("Memory Allocation failed\n");
		return ('\0');
	}
	tokened[0] = token = strtok(string, delim);

	for (index = 1; token != NULL; index++)
	{
		tokened[index] = token = strtok('\0', delim);
	}
	if (tokened[0][0] != '/')
	{
		global.command = _strdup(tokened[0], 0);
		global.command_length = _strlen(global.command);
	}
	else if (tokened[0][0] == '/')
	{
		if (!(access(tokened[0], F_OK)))
        return (tokened);
			fork_exec(tokened[0], tokened, envc);
	}
	free(token);
	return (tokened);
}*/
/*#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **parser(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}*/
/**
 * tokenizer - parses strings into tokens
 *
 * @buffer: storage space
 * Return: split tokens
 */
char **tokenizer(char *buffer)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 5);
	if (tokens == NULL)
		return (NULL);
	token = strtok(buffer, "\n \t");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n \t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}





/**
 * com_remover - removew all comments marked by #
 * @path: the string from getline
 * Return: returns string with NULL in place of #
 */

char *com_remover(char *path)
{
	int index, count;

	for (index = 0; path[index] != '\0'; index++)
	{
		count = index;
		if (path[index] == '#')
		{
			if (path[--count] == ' ' ||
			    (path[--count] && path[++count] == ' '))
			{
				path[index] = '\0';
			}
		}
	}
	return (path);
}

/**
 * double_space_remover - removes blank lines
 * @path: lines passed in
 *
 * Return: 1 on success
 */
int double_space_remover(char *path)
{
	int index;
	int count = 0;

	for (index = 0; path[index] != '\0'; index++)
	{
		if (path[index] == ' ')
		{
			count++;
			if (count  == _strlen(path))
				return (0);
		}
	}
	return (1);
}