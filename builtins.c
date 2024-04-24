#include "shell.h"

/**
 * print_env - prints enviorment like printenv
 *
 * Return: 0
*/
int print_env(void)
{
char **env_ptr = environ;

while (*env_ptr != NULL)
{
printf("%s\n", *env_ptr);
env_ptr++;
}
return (0);
}

/**
 * str_cmp - compares two strings up to n characters
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 *
 * Return:
 * 0 if the strings are equal up to n characters,
 * -1 if s1 is less than s2,
 * 1 if s1 is greater than s2.
 */
int str_cmp(const char *s1, const char *s2, int n)
{
int i = 0;

while (i < n)
{
if (s1[i] != s2[i])
return ((s1[i] < s2[i]) ? -1 : 1);
if (s1[i] == '\0')
return (0);
i++;
}
return (0);
}

/**
 * get_env - retrieves the value of an environment variable
 * @var: name of the environment variable
 *
 * Return: pointer to the value of the environment variable,
 *         or NULL if the variable is not found
 */
char *get_env(char *var)
{
int i;
for (i = 0; environ[i] != NULL; i++)
{
if (str_cmp(environ[i], var, strlen(var)) == 0)
return (&environ[i][strlen(var) + 1]);
}
return (NULL);
}

/**
 * handle_built_in_commands - handles built-in commands
 * @args: Array of strings if the provided command is a built-in command
 * and executes the corresponding action if it is. suported built-in
 * command are: exit, cd, and env
 *
 * Return: 0 on success, -1 if the command is not a built in command
*/
int handle_built_in_commands(char **args)
{
if (args == NULL || args[0] == NULL)
{
/* No command provided, treat as Ctrl+D (end-of-file condition) */
printf("\n");
return (0);
}

if (strcmp(args[0], "exit") == 0)
{
/* "exit" command detected */
return (handle_exit_command());
}
else if (strcmp(args[0], "cd") == 0)
{
/* "cd" command detected */
return (handle_cd_command(args));
}
else if (strcmp(args[0], "env") == 0)
{
/* "env" command detected */
return (handle_env_command());
}

return (-1); /* Not a built-in command */
}
