#include "shell.h"
/**
* execute - Function to execute programs.
* @args: Double pointer to the list of arguments.
* Return: 1 if args are NULL or value of args.
*/
int execute(char **args)
{
	int count, n;

	command_t commands[] = {
	{"exit", __exit},
	{"help", help},
	{"cd", cd}
	};
	/** if no args given */
	if (args[0] == NULL)
		return (1);
	/** checks args to know what command use */
	n = N_COMMANDS(commands, commands[0]);
	for (count = 0; count < n; count++)
	{
		if (_strcmp(args[0], commands[count].name) == 0)
			return (commands[count].s(args));
	}
	return (run(args));
}

