#include "monty.h"
/**
 *add - function that adds the values of the top two nodes
 *@stack:  pointer to the head of the stack list
 *Return: returns 1 on success and 0 on error
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

/**
 *_is_int - function that checks if a string can be converted to a valid
 *		integer
 *@str:  string to be checked
 *Return: returns a pointer to the duplicate string and NULL on error
 *
 */
char *_is_int(char *str)
{
	int i, n = 0, len = 0;
	char j;

	if (!str)
		return (NULL);
	len = strlen(str);
	for (i = 0; str[i]; i++)
	{
		for (j = '0'; j <= '9'; j++)
		{

			if (str[i] == j)
				n++;
		}
	}
	if (n != len)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

/**
 *_strdup - function that create a string duplicate
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

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: pointer to pointer to stack
 *
 * Return: 1 if successful otherwise 0
 */
int sub(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	(*stack)->next->n -= (*stack)->n;
	pop(stack);
	return (1);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to pointer to stack
 *
 * Return: 1 if successful
 * otherwise 0 if stack is empty or -1 if DivisionByZerro
 */
int _div(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	if ((*stack)->n == 0)
		return (-1);
	(*stack)->next->n /= (*stack)->n;
	pop(stack);
	return (1);
}
