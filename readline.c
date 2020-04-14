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
	buffer = malloc(buf_s * sizeof(char *)); /** if buffer fails "error" */
	if (!buffer)
	{
		exit(EXIT_FAILURE);
	}
	while (1) /** read line loop to get the chars. Returns the line n counts chs*/
	{
		gc = getchar();
		if (gc == '\n')
		{
			buffer[count] = '\0';
			return (buffer);
		}
		else if (gc == EOF)
		{
			return (NULL);
		}
		else
			buffer[count] = gc;
		count++;
		if (count >= buf_s)
		{
			buf_s2 = buf_s + 1024;
			buffer = _realloc(buffer, buf_s, buf_s2);
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
