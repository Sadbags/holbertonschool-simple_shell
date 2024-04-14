#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
*/
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (strcmp(input, "exit\n") == 0)
		free(input);
		exit(EXIT_SUCCESS);

	}
	free(input);
	return (0);
}
