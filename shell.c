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
		printf("simple_shell ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			perror("getline");
			exit(EXIT_SUCCESS);
		}
		if (strcmp(input, "exit\n") == 0)
		free(input);
		exit(EXIT_FAILURE);

	}
	free(input);
	return (0);
}
