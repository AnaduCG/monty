#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - push to stack_t doubly list
 * @stack: pointer to the stack
 * @n: data to push to stack
 *
 * Return: pointer to new node if successful otherwise NULL
 */
stack_t *push(stack_t **stack, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	/* update stack pointer */
	*stack = new;
	return (new);
}

/**
 * pall - print stack_t doubly list top to bottom
 * @stack: pointer to the stack
 *
 * Return: number of elements in stack
 */
size_t pall(stack_t *stack)
{
	size_t n = 0;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		n++;
		stack = stack->next;
	}
	return (n);
}

/**
 * pint - print the value at the top of the stack
 * @stack: pointer to the stack
 *
 * Return: 1 if successful otherwise 0
 */
int pint(stack_t *stack)
{
	if (!stack)
		return (0);
	printf("%d\n", stack->n);
	return (1);
}
