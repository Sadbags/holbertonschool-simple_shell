#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>

/* Prototypes */
void display_prompt(void);
char *read_input(void);
char **parse_input(char *input);
char *strtok(char *str, const char *delim);
int execute_command(char **args);

#endif
