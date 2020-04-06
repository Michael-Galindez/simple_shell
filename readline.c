#include "shell.h"
/**
 * readline - Function to read the line.
 * Return: Returns the line read.
 */
char *readline(void)
{
	int buf_s, buf_s2, count, gc;
	char *buffer;

	/** sets vars values and allocates memory */
	buf_s = 1024;
	count = 0;
	buffer = malloc(buf_s * sizeof(char *));
	/** if buffer fails (dont exist || = NULL) "error" */
	if (!buffer)
	{
		exit(EXIT_FAILURE);
	}
	/** read line looping to get the chars. Returns the line and counts chars*/
	while (1)
	{
		gc = getchar();
		if (gc == EOF || gc == '\n')
		{
			buffer[count] = '\0';
			return (buffer);
		}
		else
			buffer[count] = gc;
		count++;
		if (count >= buf_s)
		{
			buf_s2 = buf_s + 1024;
			buf_s = buf_s2;
			/** if fails to allocate error msg in standard error */
			if (!buffer)
			{
				fprintf(stderr, ">$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
