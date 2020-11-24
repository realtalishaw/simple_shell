#include "shell.h"




char **tokenizer(char *buffer)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
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
