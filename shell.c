#include "shell.h"

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void);

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
    char *token;
    pid_t pid;

    while (1)
    {
        display_prompt();

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }

        num_args = 0;
        token = strtok(input, " ");
        while (token != NULL && num_args < MAX_ARGS - 1)
        {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
            {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
    char display_prompt[] = "$ ";
    write(STDOUT_FILENO, display_prompt, 2);
}
