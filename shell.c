#include "shell.h"

/**
 * main - print prompt, handle EOF, read file_stream
 * @argc: arg count (not needed)
 * @argv: argv for command
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
char *s = NULL;
size_t buffer_size = 0;
ssize_t file_stream = 0;
char *name = argv[0];

(void)argc;

while (1)
{
if (isatty(STDIN_FILENO) == 1)
write(1, "simple_shell ", 13);
file_stream = getline(&s, &buffer_size, stdin);
if (file_stream == -1)
{
if (isatty(STDIN_FILENO) == 1)
write(1, "\n", 1);
break;
}

if (s[file_stream - 1] == '\n')
s[file_stream - 1] = '\0';
if (*s == '\0')
continue;
if (_cmdread(s, file_stream, name) == 2)
{
free(s);
exit(EXIT_SUCCESS);
}
}
free(s);
s = NULL;
return (0);
}

/**
 * _cmdread - handles command line and tokenizes it
 *@s: string
*@file_stream: getline input
*@name: name of the command
* Return: 0
*/
int _cmdread(char *s, size_t __attribute__((unused)) file_stream, char *name)
{
char *token = NULL;
char *cmdarr[100];
int i;

if (s == NULL)
return (0);

if (_strcmp(s, "exit") == 0)
return (2);

if (_strcmp(s, "env") == 0)
return (print_env());

token = strtok(s, " "), i = 0;
while (token)
{
cmdarr[i++] = token;
token = strtok(NULL, " ");
}
if (i == 0)
return (0);

cmdarr[i] = NULL;
return (_callcommand(cmdarr, name));
}

/**
 * print_not_found - prints when cmd is not found in path
 *
 * @cmd: a string provided by the stdin
 * @name: name of the command
 */
void print_not_found(char *cmd, char *name)
{
write(2, name, _strlen(name));
write(2, ": ", 2);
write(2, "no such file or directory: ", 27);
write(2, cmd, _strlen(cmd));
write(2, "\n", 1);
}

/**
 * _callcommand - calls cmd, forks, execve
 *
 * @cmd_arr: a string provided by the stdin
 * @name: name of the command
 * Return: 0
 */
int _callcommand(char *cmd_arr[], char *name)
{
char *_exe_path_str = NULL;
char *_cmd = NULL;
pid_t is_child;
int status;

_cmd = cmd_arr[0];
_exe_path_str = path_finder(_cmd);
if (_exe_path_str == NULL)
{
print_not_found(_cmd, name);
return (3);
}
is_child = fork();
if (is_child < 0)
{
perror("Error:");
return (-1);
}
if (is_child > 0)
wait(&status);
else if (is_child == 0)
{
(execve(_exe_path_str, cmd_arr, environ));
perror("Error:");
exit(1);
}
free(_exe_path_str);
return (0);
}
