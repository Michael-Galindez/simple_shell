#include "shell.h"
/**
 * main - function thattakes commands from the user, stdin.
 * @argc: arguments.
 * @argv: arguments.
 * Return: Always  zero.
 */
int main(int argc, char **argv)
{
  (void) argc, (void) argv;
  char *l;
  int checker;
  char **args;


do {
    /** Prints Prompt To User */
    printf("SH>$ ");
    /** reads the line */
    l = readline();
    /** Separates the line to take and delims commands */
    args = separate(l);
    /** Execute the commands given by the user */
    checker = execute(args);
}
/** while executes args */
while (checker);
return (0);
}
