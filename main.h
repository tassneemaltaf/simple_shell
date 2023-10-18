#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_ARGUMENTS 1024

char *find_path(char *command, char *env[]);
int _strcmp(char *s1, char *s2, int n);
char **tokenize(char *str, char *delim);
int _strlen(char *s);
void print(char *message);
int get_arg_count(char *buffer, char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src, int n);
void _printenv(char **env);
void print_error(char *command, char *message, char *filename, int err_no);

#endif
