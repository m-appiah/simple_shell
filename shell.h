#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>

extern char **environ;
extern int count;

void _prompt(void);
char *read_input();
int builtins(char **argv_tokens);
char *search_directory(char *directory, char *command);
char **tokenize_input(char *input, int *num_tokens);
void execute_command(char **argv, char **prog);
int _putchar(char c);
void error_msg(char *prog, int count, char *cmd);
void _puts(char *str);
void execmd(char **argv, char **prog);
char *get_location(char *command);
void print_env(char **environ);
char *_strcat(char *dest, char *src);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(char *name);

#endif
