#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ;
int _strlen(char *str);
int _puts(char *str);
void display_prompt(void);
char *_strdup(char *str);
char **toknize(char *command, char *delimiter);
char *_strcpy(char *dest, char *src);
void printError(char *str);

typedef struct
{
	char *key;
	char *value;
} envVarNode;

int lenOfArray(char **environ);
int _strcmp(char *string, char *string2);
char *getEnv(char *name);
void execute_command(char **argv);
void fork_and_execute(char **argv);
char *handle_path(char *pathName, char *prog);
char *_strcat(char *dest, char *src);
char **copyArrayOfStrings(char **argv);
void freeArrayOfStrings(char **array);

#endif /* SHELL_H */
