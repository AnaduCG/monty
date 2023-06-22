#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * handle_push - handle the opcode push
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_push(stack_t **stack, unsigned int line_number, void *arg)
{
	char *n = _is_int(arg);

	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!push(stack, atoi(n)))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		free(n);
		exit(EXIT_FAILURE);
	}
	 free(n);
}

/**
 * handle_pall - handle the opcode pall
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_pall(stack_t **stack, int line_number __attribute__((unused)),
		 void *arg __attribute__((unused)))
{
	pall(*stack);
}

/**
 * handle_pint - handle the opcode pint
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_pint(stack_t **stack, unsigned int line_number,
		 void *arg __attribute__((unused)))
{
	int n = pint(*stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *handle_pop - function that handles error for the pop funtion
 *@stack: pointer to pointer to head node of the stack list
 *@line_number: file index
 *@arg: argument of instruction
 */
void handle_pop(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int n = pop(stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 *handle_swap - function that handles for the swap function
 *@stack: pointer to pointer to head node of the stack list
 *@line_number: file index
 *@arg: argument of instruction
 */
void handle_swap(stack_t **stack, unsigned int line_number,
		 void *arg __attribute__((unused)))
{
	int n = swap(stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
