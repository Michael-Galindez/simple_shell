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
	perror("SH>$: Expected arg to \"cd\"\n");
	else
	{
		if (chdir(args[1]) == 0)
		{
			if (getcwd(buf, 4000) == NULL)
				perror("unable to print dir");
			else
				_puts(buf);
			_puts("\n");
		}
		else
			perror("error on cd");
	}
	return (1);
}
/**
 * help - Function to look for help info
 * Return: always 1.
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
	_puts("Available commands are:\n");
	count = 0;
	while (count < n)
	{
		_puts(commands[count].name);
		_puts("\n");
		count++;
	}
	return (1);
}
