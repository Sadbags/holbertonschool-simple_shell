#include "shell.h"

/**
 * token - Tokenizes a string into tokens separated by a space character
 * @input: The input string to tokenize
 * @tokens:pointer to an array of strings to store the tokens
 * @max_tokens: The maximum number of tokens to store
 *
 * Return: The number of tokens found
*/
int token(char *input, char *tokens[], int max_tokens)
{
	int count = 0;
	char *token = strtok(input, " ");

	while (token != NULL && count < max_tokens)
	{
		tokens[count++] = token;
		token = strtok(NULL, " ");
	}
	return (count);
}
