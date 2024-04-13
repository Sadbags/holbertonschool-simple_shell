#include "shell.h"

int execute_command(char *command)
{
	int result = system(command);

	if (result == -1)
	{
	perror("system");
	return (-1);
	}
	else
	{
		return (0);
	}
}
