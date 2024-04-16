#include "shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
    printf("$ ");
}

/**
 * read_input - Reads input from the user
 *
 * Return: Pointer to the input string
 */
char *read_input(void)
{
    char *input = malloc(MAX_INPUT_LENGTH);
    if (!input)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    input[strcspn(input, "\n")] = '\0';
    return input;
}

/**
 * parse_input - Parses input into tokens
 * @input: Input string to be parsed
 *
 * Return: Array of pointers to tokens
 */
char **parse_input(char *input)
{
    char **args = malloc(MAX_INPUT_LENGTH * sizeof(char *));
    char *token;
    int i = 0;

    if (!args)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " ");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return args;
}


/**
 * execute_command - Executes the command
 * @args: Array of command and arguments
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
