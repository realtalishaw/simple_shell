#include "shell.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);
	token = strtok(str, "\n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
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
