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
args = parse_input(input);
execute_command(args);
free(input);
free(args);
}

return (0);
}
