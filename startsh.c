#include "shell.h"
/**
 * sig_handler - Function to handle the signal
 * @uuv: unused input variable.
 */
static void sig_handler(int uuv)
{
	unsigned int sig_flag = 0;
	(void) uuv;

	if (sig_flag == 0)
		puts("\nSH>$ ");
	else
		puts("\n");
}
/**
 * main - function thattakes commands from the user, stdin.
 * @argc: Arguments to use.
 * @argv: Double pointer to the array of arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *l, **args;
	int checker;
	(void) argc, (void) argv;

	do {

		/** Prints Prompt To User */
		printf("SH>$ ");
		signal(SIGINT, sig_handler);
		/** reads the line */
		l = readline();
		/** Separates the line to take and delims commands */
		args = separate(l);
		/** Execute the commands given by the user */
		checker = execute(args);

		free(args);
		free(l);
	} while (checker);
	return (0);
}
