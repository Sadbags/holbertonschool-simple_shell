#include "shell.h"

#define MAX_PATH_LENGTH 1024

/**
 * path_command - Finds the full path of a command
 * @cmd: The command to find
 *
 * Return: Pointer to the full path of the command if found, NULL otherwise
 */
char *path_command(const char *cmd)
{
char *path = get_env("PATH");
char *path_copy;
char *dir;
struct stat sb;

if (path == NULL)
{
fprintf(stderr, "PATH environment variable not set\n");
return (NULL);
}

path_copy = strdup(path);
if (path_copy == NULL)
{
perror("Memory allocation failed");
return (NULL);
}

dir = strtok(path_copy, ":");
while (dir != NULL)
{
char full_path[MAX_PATH_LENGTH];
sprintf(full_path, "%s/%s", dir, cmd);

if (stat(full_path, &sb) == 0 && S_ISREG(sb.st_mode) && sb.st_mode & S_IXUSR)
{
char *command_path = strdup(full_path);
free(path_copy);
return (command_path);
}

dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}
