#include "shell.h"
/**
 * ReadLine - reads the line.
 * Return: returns the line readed by the function.
 */
char *readline(void)
{
int buf_s, buf_s2, count, c;
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

/** reat line using while to go thru it and get chars, also returns the line and count counts the chars*/
while (1)
    {
      c = getchar();
      if (c == EOF || c == '\n')
	{
	  buffer[count] = '\0';
	  return (buffer);
	}
      else
	buffer[count] = c;
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
