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
	char *tokens[100];

	while (1)
	{
		printf("$ ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(input);
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			free(input);
			exit(EXIT_FAILURE);
		}

		if (input[read - 1] == '\n')
		    input[read - 1] = '\0';

		if (strcmp(input, "") == 0)
		continue;

		token(input, tokens, 100);

		if (execute_command(tokens[0]) == -1)
            fprintf(stderr, "command not found: %s\n", tokens[0]);

		free(input);

		input = NULL;
		len = 0;
	}

	return (0);
}
