#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to pointer to stack
 */
void rotl(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	/* pop the top element */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	/* insert at the end of the stack */
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
}

/**
 * rotr - rotate the stack to the bottom
 * @stack: pointer to pointer to stack
 */
void rotr(stack_t **stack)
{
	stack_t *current = *stack, *prev = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	/* remove the last element from the stack */
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	/* push last element to stack */
	if (!push(stack, current->n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	free(current);
}

/**
 * enqueue - add element to the end of the stack
 * @stack: pointer to stack
 * @n: data to push to stack
 *
 * Return: pointer to new node if successful otherwise NULL
 */
stack_t *enqueue(stack_t **stack, int n)
{
	stack_t *current = *stack, *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	} else
	{
		/* tranverse to the end of the stack */
		while (current->next != NULL)
			current = current->next;
		/* add new node */
		current->next = new;
		new->prev = current;
	}
	return (new);
}
