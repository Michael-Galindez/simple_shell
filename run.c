#include "shell.h"
/**
 * run - runs the program with fork.
 * @args: arguments.
 * Return: always 1.
 */
int run(char **args)
{
int status;
pid_t pid;

/** child process */
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
perror("execvp failed");
exit(EXIT_FAILURE);
}
else if (pid < 0)
/**  if error forking */
perror(">$ ");
else
/** Parent process */
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}