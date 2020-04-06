#include "shell.h"
/**
 * main - function thattakes commands from the user, stdin.
 * @argc: Arguments to use.
 * @argv: Double pointer to the array of arguments.
 * Return: Always zero.
 */
int main(int argc, char **argv)
{
	(void) argc, (void) argv;
	char *l, **args;
	int checker;

	do {
		/** Prints Prompt To User */
		printf("SH>$ ");
		/** reads the line */
		l = readline();
		/** Separates the line to take and delims commands */
		args = separate(l);
		/** Execute the commands given by the user */
		checker = execute(args);
	} while (checker);
	return (0);
}
