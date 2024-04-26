#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "simple_shell "

int print_env(void);
int _str_n_cmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
int _cmdread(char *s, size_t __attribute__((unused)) file_stream, char *name);
int _strlen(char *s);
int _callcommand(char *cmd_arr[], char *name);
char *_strdup(char *string);
char *path_finder(char *cmd);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_env(char *var);
void print_not_found(char *cmd, char *name);

#endif
