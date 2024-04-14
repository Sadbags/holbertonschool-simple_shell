#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 256

void displayPrompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

char *readCommand(void)
{
    static char command[MAX_COMMAND_LENGTH];
    char *newlinePos;

    if (fgets(command, sizeof(command), stdin) != NULL)
    {
        newlinePos = strchr(command, '\n');
        if (newlinePos != NULL)
        {
            *newlinePos = '\0';
        }
        return command;
    }
    else
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    }
}

void executeCommand(const char *command)
{
    if (execlp(command, command, NULL) == -1)
    {
        perror("execlp");
        exit(EXIT_FAILURE);
    }
}
