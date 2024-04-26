## holbertonschool-simple_shell


## Objective

Write a UNIX command interpreter.

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## Description

- What is shell?

Shell is a command-line interpreter or shell that provides a command line user for Unix-like operating systems. The Shell is a program that takes the command inputs from the user and passes them to the machines to execute them through the kernel.

- What is a kernel?

A kernel is the core component of an operating system (OS) that manages the system's resources and provides essential services to software applications like disks, RAM, CPU, etc.

- What is EOF?

End of file is a condition that terminates the program using (Ctrl+D) and exits to the terminal.

- What is pid and ppid?

* pid : The process identifier (PID) is to identify an active process.
* ppid : The parent process ID is the number assigned to the process of a given process in an operating process.

- What if fork()?

It creates a new process duplicating the process that makes the call.

- What is wait()?

It waits for the child to finish and it recovers the status of its exit.

## General Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded.

## Allowed functions & system calls

* all functions from string.h
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* printf (man 3 printf)
* fprintf (man 3 fprintf)
* vfprintf (man 3 vfprintf)
* sprintf (man 3 sprintf)
* putchar (man 3 putchar)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Compilation

Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```
## Authors

* Bryan Garcia
* Ginna Figueroa
* Ricardo Sanchez