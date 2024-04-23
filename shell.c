#include "shell.h"

/**
 * main - Runs the Simple Shell
 * @ac: Argument count
 * @av: Argument vector
 * @env: environment
 * Return: 0
 */
int main(int ac, char **av,  char **env)
{
	char *pointer = NULL, **tokens = NULL;
	int flag;
	size_t n = 0;
	(void) av;
	(void) ac;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		flag = getline(&pointer, &n, stdin);

		/* Victor, here goes the if statement to handle EOF */
		// Check if EOF is reached or an error occurred
        if (flag == -1 && feof(stdin)) {
            printf("\n"); // Print a newline for better formatting
            break; // Exit the loop
        } else if (flag == -1) {
            perror("getline"); // Print an error message if getline fails
            break; // Exit the loop
        }
		if (pointer[0] == '\n' || pointer[0] == ' ')
		{
			free(pointer);
			pointer = NULL;
			continue;
		}

		tokens = tokenization(pointer, " \n");
		comp_exec(tokens, pointer, env);
	}
	return (0);
}
