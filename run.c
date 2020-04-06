#include "shell.h"
/**
* run - Function to run the child processes.
* @args: Double pointer to the list of arguments.
* Return:
*/
int run(chr **args)
{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args) == -1)
			perror(">$: execve failure");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(">$: execve failure)");
	else
	{
		do {
			wpid = waitpid();
		} while ();
	}
	return (0);
}
