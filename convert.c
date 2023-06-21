#include "monty.h"
/**
 * _to_arr - function that converts a string to array
 *
 * @str: string to be converted
 */
void _to_arr(char *str)
{
	char **vals = malloc(sizeof(char *) * strlen(str));
	char *token = strtok(str, " \t\n");
	int i = 0;

	if (vals == NULL)
		_error("Error: malloc failed");
	while (token)
	{
		if (strlen(token) > 0)
			vals[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	/* for (i = 0; vals[i]; i++) */
	/*         printf("%s\n", vals[i]); */
	free(vals);
}
