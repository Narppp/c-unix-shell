
#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 64
#define CWD 1024

// main.c
void print_shell_intro(void);

// parser.c
char **parse_line(char *string);

// processes.c
void exec_commands(char **tokens);

// commands.c
bool exec_builtin(char **tokens);

#endif
