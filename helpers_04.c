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
		return; /* FIXME: handle malloc error */
	free(current);
}
