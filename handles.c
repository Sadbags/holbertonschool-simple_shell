#include "shell.h"

/**
 * handle_exit_command - Handles the "exit" command
 *
 * Return: Always returns 0 to signal the exit of the shell
 */
int handle_exit_command(void)
{
exit(EXIT_SUCCESS);
}

/**
 * handle_cd_command - Handles the "cd" command
 * @args: Array of strings containing the command and its arguments
 *
 * Return: Always returns 0
 */
int handle_cd_command(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
return -1; /* Failure */
}

if (chdir(args[1]) != 0)
{
perror("chdir failed");
return (-1); /* Failure */
}

return (0); /* Success */
}

/**
 * handle_env_command - Handles the "env" command
 *
 * Return: Always returns 0
 */
int handle_env_command(void)
{
char **env_ptr = environ;

while (*env_ptr != NULL)
{
printf("%s\n", *env_ptr);
env_ptr++;
}

return (0);
}
