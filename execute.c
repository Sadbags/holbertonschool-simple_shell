#include "shell.h"
/**
 * execute_builtin_command - Executes a built-in command
 * @args: Array of strings containing the command and its arguments
 *
 * Return: 1 on success, -1 on failure
 */
int execute_builtin_command(char **args)
{
if (strcmp(args[0], "exit") == 0)
{
/* "exit" command detected */
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "cd") == 0)
{
/* "cd" command detected */
return (execute_cd_command(args));
}

return (0); /* Not a built-in command */
}

/**
 * execute_cd_command - Executes the "cd" command
 * @args: Array of strings containing the command and its arguments
 *
 * Return: 1 on success, -1 on failure
 */
int execute_cd_command(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
return (-1); /* Failure */
}

if (chdir(args[1]) != 0)
{
perror("chdir failed");
return (-1); /* Failure */
}

return (1); /* Success */
}

/**
 * execute_command - Executes the command provided by the user
 * @args: Array of strings containing the command and its arguments
 *
 * Return: 1 on success, -1 on failure
 */
int execute_command(char **args)
{
if (args == NULL || args[0] == NULL)
{
/* No command provided, treat as Ctrl+D (end-of-file condition) */
printf("\n");
exit(EXIT_SUCCESS);
}

if (execute_builtin_command(args) == 1)
{
/* Built-in command executed successfully */
return (1);
}

return (execute_external_command(args));
}

/**
 * execute_external_command - Executes an external command.
 * @args: Array of strings containing the command and its arguments.
 *
 * Return: 1 on success, -1 on failure.
 */
int execute_external_command(char **args)
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

return (1); /* Successful execution */
}
