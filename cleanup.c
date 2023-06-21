#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - free the stack_t doubly list
 * @stack: pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *tmp = NULL;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL; /* set the stack ptr to NULL to indicate empty list */
}
