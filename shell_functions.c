#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
printf("simple_shell$ ");
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
free(input);
exit(EXIT_SUCCESS);
}

input[strcspn(input, "\n")] = '\0';
return (input);
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
 * execute_command - Executes the command provided by the user
 * @args: Array os strings containing the command and its arguments
 *
 * Return: 1 on success, -1 on failure
*/
int execute_command(char **args)
{
pid_t pid;
int status;

if (args == NULL || args[0] == NULL)
{
/* No command provided, treat as Ctrl+D (end-of-file condition) */
printf("\n");
exit(EXIT_SUCCESS);
}

if (strcmp(args[0], "exit") == 0)
{
/* "exit" command detected */
exit(EXIT_SUCCESS);
}

pid = fork();
if (pid < 0)
{
perror("fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("execvp failed");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}

return (1);
}

int main()
{
    char **args;
    char input[MAX_INPUT_LENGTH];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    /* Remove trailing newline character */
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    args = parse_input(input);
    execute_command(args);

    free(args);

    return 0;
}

