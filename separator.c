#include "shell.c"
#define DELIMETER " "
/**
 * separate - Function to separate tokens.
 * @l: Chars that commes in.
 * Return: Tokens' values.
 */
char **separate(char *l)
{
	int buf_s = 64, buf_s2, count = 0;
	char **tokens, *token;

	tokens = malloc(buf_s * sizeof(char *));
	/** if tokens failed to allocate */
	if (!tokens)
	{
		fprintf(stderr, ">$: allocation error at parsel\n");
		exit(EXIT_FAILURE);
	}
	/** checks token with DELIMETER user counter to measure position */
	token = strtok(l, DELIMETER);
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		if (count >= buf_s)
		{
			buf_s2 = buf_s + 64;
			buf_s = buf_s2;
		}
		if (!tokens)
		{
			fprintf(stderr, ">$: allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
	token = strtok(NULL, DELIMETER);
	{
		tokens[count] = NULL;
		return (tokens);
	}
}
