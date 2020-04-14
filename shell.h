#ifndef SHELL_H
#define SHELL_H
#define N_COMMANDS(x, y) (sizeof(x) / sizeof(y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
/**
 * struct command_t - pointers to builtins.
 * @name: name of the command.
 * @s: pointer to command.
 */
typedef struct command_t
{
char *name;
int (*s)();

} command_t;

char *readline(void);
char **separate(char *l);
int execute(char **args);
int run(char **args);
int __exit(void);
int help(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int cd(char **args);
int main2(void);
int _putchar(char c);
void _puts(char *str);
#endif
