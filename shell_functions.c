#include "shell.h"

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

return (args);
}

/**
 * strtok - Parses a string into tokens
 * @str: The string to be parsed
 * @delim: The delimiter character
 *
 * Return: A pointer to the next token
 */
char *strtok(char *str, const char *delim)
{
static char *buffer = NULL;
char *start;
char *end;

if (str != NULL)
buffer = str;
if (buffer == NULL)
return (NULL);

start = buffer;
end = buffer;

while (*end != '\0')
{
if (strchr(delim, *end) != NULL)
{
*end = '\0';
buffer = end + 1;
return (start);
}
end++;
}

buffer = NULL;
return (start);
}

/**
 * execute_command - Executes the command provided by the user
 * @args: Array of strings containing the command and its arguments
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

if (strcmp(args[0], "cd") == 0)
{
/* "cd" command detected */
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
return (-1);
}

if (chdir(args[1]) != 0)
{
perror("chdir failed");
return (-1);
}
return (1);
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
