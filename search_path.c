#include "shell.h"

/**
 * search_path - Search for the command in the directories listed in the PATH
 * @command: The command to search for
 *
 * Return: The full path of the command if found, NULL otherwise
 */
char *search_path(char *command)
{
    char *path = getenv("PATH");
    char *token, *path_copy, *full_path;

    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not set\n");
        return (NULL);
    }

    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("strdup failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL)
        {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        sprintf(full_path, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
