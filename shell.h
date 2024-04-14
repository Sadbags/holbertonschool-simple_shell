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
void executeCommand(const char *command);
char *readCommand(void);
void displayPrompt(void);

#endif
