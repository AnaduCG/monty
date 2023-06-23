#include "monty.h"
/**
 * comment - function that converts a string to array
 * @line_number: argument ofr tracking line number in file
 * @str: string to be converted
 * @stack: pointer to pointer to stack
 */
void comment(char *str, unsigned int line_number, stack_t **stack)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
	}
	_to_arr(str, line_number, stack);
}

/**
 * _to_arr - function that converts a string to array
 * @line_number: argument ofr tracking line number in file
 * @str: string to be converted
 * @stack: pointer to pointer to stack
 */
void _to_arr(char *str, unsigned int line_number, stack_t **stack)
{
	char **vals = malloc(sizeof(char *) * (strlen(str) + 1));
	char *token = strtok(str, " \t\n");
	int i = 0;

	if (vals == NULL)
		_error("Error: malloc failed\n");
	if (!token || str[0] == '\0')
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

	run_instruction(stack, line_number, vals);
}
