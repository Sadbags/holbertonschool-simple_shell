#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024
extern char **environ;
#define PROMPT "simple_shell "

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>

/* Prototypes */
void display_prompt(void);
char *read_input(void);
char **parse_input(char *input);
char *strtok(char *str, const char *delim);
int print_env(void);
int str_cmp(const char *s1, const char *s2, int n);
char *get_env(char *var);
char *path_command(const char *cmd);
int execute_external_command(char **args);
int execute_command(char **args);
int execute_cd_command(char **args);
int execute_builtin_command(char **args);
int handle_exit_command(void);
int handle_cd_command(char **args);
int handle_env_command(void);


#endif
