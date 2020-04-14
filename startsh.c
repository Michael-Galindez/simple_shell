#include "shell.h"
/**
 * sig_handler - Function to handle the signal
 * @uuv: unused input variable
 */
static void sig_handler(int uuv)
{
	unsigned int sig_flag = 0;
	(void) uuv;

	if (sig_flag == 0)
		puts("\n$ ");
	else
		puts("\n");

}
/**
 * main - function thattakes commands from the user, stdin.
 * Return: Always 0.
 */
int main(void)
{
	char *l, **args;
	int checker;

	signal(SIGINT, sig_handler);

	if (isatty(STDIN_FILENO) != 0)
	{
		do {

		/** Prints Prompt To User */
		printf("$ ");
		/** reads the line */
		l = readline();
		/** Separates the line to take and delims commands */
		args = separate(l);
		/** Execute the commands given by the user */
		checker = execute(args);

		free(args);
		free(l);

	} while (checker);
	}
	else
	{
		main2();
	}
	return (0);
}
/**
 * main2 - Function to read and separate
 * Return: Always 0.
 */
int main2(void)
{
	char *l, **args;

	do {
		signal(SIGINT, sig_handler);
		/** reads the line */
		l = readline();
		if (l == NULL)
		{
			free(args);
			free(l);
			break;
		}
    /** Separates the line to take and delims commands */
		args = separate(l);
    /** Execute the commands given by the user */
		execute(args);
	} while (1);
	return (0);
}
