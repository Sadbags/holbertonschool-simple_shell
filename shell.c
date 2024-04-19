#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0
*/
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
break;
}

args = parse_input(input);
if (args == NULL)
{
free(input);
continue;
}

if (execute_command(args) == 0)
{
free(input);
free(args);
break;
}

free(input);
free(args);
}

return (0);
}
