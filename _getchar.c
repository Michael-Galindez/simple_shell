#include "shell.h"
/**
* _getchar - function to read
* Return: the character read as an
*/
int _getchar(void)
{
ssize_t file_descriptor = 0, file_position = 0;
char temp_buffer[1], *read_char;
file_position = read(file_descriptor, temp_buffer, 1);
if (file_position == -1)
{
perror("$ Error reading from Standard Input");
return (0);
}
else if (file_position > 0)
{
read_char = temp_buffer;
return ((int)*read_char);
}
return (EOF);
}
