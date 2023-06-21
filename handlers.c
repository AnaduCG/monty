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
	char *n = (char *)arg;
	stack_t *ret_val;

	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
	ret_val = push(stack, atoi(n));
	if (!ret_val)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
}

/**
 * handle_pall - handle the opcode pall
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_pall(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int n = pall(*stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
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
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
}
/**
 *handle_pop - function that handles error for the pop funtion
 *@stack: pointer to pointer to head node of the stack list
 *@line_number: file index
 *@arg: argument of instructio
 */
void handle_pop(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int n = pop(stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
}
/**
 *handle_swap - functio that handles for the swap function
 *@stack: pointer to pointer to head node of the stack list
 *@line_number: file index
 *@arg: argument of instructio
 */
void handle_swap(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int n = swap(stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
}
