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
