#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

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

