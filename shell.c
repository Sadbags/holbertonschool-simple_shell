#include "shell.h"

int main(void)
{
    char *input;
    char **args;

    while (1)
    {
        display_prompt();

        input = read_input();
        if (input == NULL)
        {
            printf("\n");
            break; /* End of file condition (Ctrl+D) */
        }

        args = parse_input(input);
        if (args == NULL)
        {
            free(input);
            continue; /* Skip to the next iteration */
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free(input);
            free(args);
            return (0); /* Exit the shell loop */
        }

        if (strcmp(args[0], "/bin/ls") == 0)
        {
            /* Execute the command directly */
            execute_command(args);
        }
        else
        {
            // Execute the command normally
            if (execute_command(args) == 0)
            {
                free(input);
                free(args);
                break; /* Command executed successfully */
            }
        }

        free(input);
        free(args);
    }

    return (0);
}
