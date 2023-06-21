#include "monty.h"

/**
 * _to_arr - function that converts a string to array
 * @line_number: argument ofr tracking line number in file
 * @str: string to be converted
 */
void _to_arr(char *str, unsigned int line_number)
{
	char **vals = malloc(sizeof(char *) * (strlen(str) + 1));
	char *token = strtok(str, " \t\n");
	int i = 0;
	static stack_t *stack;

	if (vals == NULL)
		_error("Error: malloc failed");
	if (!token)
	{
		free(vals);
		return;
	}

	while (token)
	{
		if (strlen(token) > 0)
			vals[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
		if (i == 2)
			break;
	}
	vals[i] = NULL;

	run_instruction(&stack, line_number, vals);

	free(vals);
}
