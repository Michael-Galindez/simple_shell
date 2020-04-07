#include "shell.h"
/**
 * __exit - Function to exit
 * Return: Always 0.
 */
int __exit(void)
{
	return (0);
}
/**
 * cd - Function to change directory.
 * @args: Double pointer to the arguments.
 * Return: Always 1.
 */
int cd(char **args)
{
	char buf[4000];
	/** if args */
	if (args[1] == NULL)
		fprintf(stderr, "SH>$: Expected arg to \"cd\"\n");
	else
	{
		if (chdir(args[1]) == 0)
		{
			if (getcwd(buf,4000) == NULL)
				perror("unable to print dir");
			else
				printf("%s\n", buf);
		}
		else
			perror("error on cd");
	}
	return (1);
}
/**
 * help - Function to look for help info
 */
int help(void)
{
	int count, n;
	command_t commands[] = {
	{"exit", __exit},
	{"cd", cd},
	{"help", help}
};
	/** prints avalible commands */
	n = N_COMMANDS(commands, commands[0]);
	printf("Available commands are:\n");
	count = 0;
	while (count < n)
	{
		printf("%s\n", commands[count].name);
		count++;
	}
	return (1);
}
