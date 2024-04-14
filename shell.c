#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 256

int main(void);

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char buffer[MAX_COMMAND_LENGTH];
    size_t length;
    pid_t pid;

    while (1) {

        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        strncpy(command, buffer, sizeof(command));

        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {

            execlp(command, command, NULL);

            perror(command);
            exit(EXIT_FAILURE);
        } else {

            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
