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
		_error("Error: malloc failed");
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
/**
 *pop - function that perfoms LIFO on the stack list
 *@stack: pointer to the head of the stack list
 *Return: 1 if successful otherwise 0
 */
int pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return (0);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return (1);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	return (1);
}
/**
 *swap - function that swaps the first and second node in the list
 *@stack: pointer to the head of the stack list
 *Return: 1 if successful otherwise 0Return: 1 if successful otherwise 0
 */
int swap(stack_t **stack)
{
	stack_t *top, *second;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	top = *stack;
	second = (*stack)->next;
	temp = top->n;
	top->n = second->n;
	second->n = temp;
	return (1);
}
