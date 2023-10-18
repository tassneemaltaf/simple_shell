#include "main.h"

/**
 * tokenize - tokenizes a string by a delimitor
 * @str: the string
 * @delim: the delimitor
 * Return: an array of tokens of the string str
 */
char **tokenize(char *str, char *delim)
{
	char **tokens;
	char *token;
	int i = 0;

	if (str == NULL || delim == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * MAX_ARGUMENTS);
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	return (tokens);
}
