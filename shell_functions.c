#include "shell.h"

/**
 * displayprompt - displays and waits for input
 *
 * Return: void
*/
void displayprompt(void)
{
	char *displayprompt = "#cisfun$";
	write(STDOUT_FILENO, displayprompt, _strlen(displayprompt));
}

/**
 * read_line - reads user input
 *
 * Return: string of user input
*/
char *read_line(void)
{
	int len = 0;
	size_t buffsize = 0;
	char *line = NULL;

	len = getline(&line, buffsize, stdin);

	if (len == EOF)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	line[len - 1] = '\0';

	return (line);
}
