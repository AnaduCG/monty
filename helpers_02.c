#include "monty.h"
/**
 *add - function that addds the values of the top two nodes
 *@stack:  pointer to the head of the stack list
 *Return: returns 1 on sucess and 0 on error
 *
 */
int add(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	(*stack)->next->n += (*stack)->n;
	pop(stack);
	return (1);
}

char *_is_int(char *str)
{
	int i, n = 0, len = 0;
	char j;

	if (!str)
		return (NULL);
	len = strlen(str);
	for (j = '0'; j <= '9'; j++)
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] == j)
				n++;
		}
	}
	if (n != len)
		return (NULL);
	return (str);
}
/**
 *__strdup - function that create a string duplicate
 *@str:  string to be duplicated
 *Return: returns a pointer to the duplicate string and NULL on error
 *
 */
char *_strdup(const char *str)
{
	size_t len = 0;
	char *new_str = NULL;

	if (str == NULL)
		return (NULL);

	len = strlen(str) + 1;
	new_str = malloc(len);
	
	if (new_str != NULL)
		memcpy(new_str, str, len);

	return (new_str);
}
