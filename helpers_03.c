#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: pointer to pointer to stack
 *
 * Return: 1 if successful otherwise 0
 */
int mul(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	(*stack)->next->n *= (*stack)->n;
	pop(stack);
	return (1);
}

/**
 * mod - computes the remainder of the division of the second
 * top element of the stack by the top of the stack
 * @stack: pointer to pointer to stack
 *
 * Return: 1 if successful otherwise 0
 * otherwise 0 if stack is empty or -1 if DivisionByZerro
 */
int mod(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	if ((*stack)->n == 0)
		return (-1);
	(*stack)->next->n %= (*stack)->n;
	pop(stack);
	return (1);
}

/**
 * _isascii - checks if integer is ascii
 * @n: integer
 *
 * Return: 1 if successful otherwise 0
 */
int _isascii(int n)
{
	if (n >= 32 && n <= 126)
		return (1);
	return (0);
}


/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 *
 * Return: 1 if successful
 * otherwise 0 if stack is empty or -1 if integer is not ascii
 */
int pchar(stack_t *stack)
{
	if (stack == NULL)
		return (0);
	if (_isascii(stack->n) == 0)
		return (-1);
	printf("%c\n", stack->n);
	return (1);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 */
void pstr(stack_t *stack)
{
	while (stack && stack->n != 0
			&& _isascii(stack->n) == 1)
	{
		printf("%c", stack->n);
		stack = stack->next;
	}
	printf("\n");
}
