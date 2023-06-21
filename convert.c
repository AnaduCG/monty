#include "monty.h"
/**
 * _to_arr - function that converts a string to array
 *
 * @str: string to be converted
 */
void _to_arr(char *str, unsigned int line_number)
{
	char **vals = malloc(sizeof(char *) * strlen(str));
	char *token = strtok(str, " \t\n");
	int i = 0;
	static stack_t *stack;

	if (vals == NULL)
		_error("Error: malloc failed");
	while (token)
	{
		if (strlen(token) > 0)
			vals[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	run_instruction(&stack, line_number, vals);
	free(vals);
}
