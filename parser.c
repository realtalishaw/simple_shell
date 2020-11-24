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
