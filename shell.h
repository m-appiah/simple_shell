#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void _prompt(void);
char *read_input();
char *search_directory(char *directory, char *command);
char **tokenize_input(char *input, int *num_tokens);
void execute_command(char **argv);
int _putchar(char c);
int _printstr(char *str);
void execmd(char **argv);
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
