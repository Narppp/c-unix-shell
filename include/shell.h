
#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>

#define BUF_SIZE 64

// parser.c
char **parse_line(char *charline);

#endif
