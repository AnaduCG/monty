#include "monty.h"
/**
 *handle_add - function that handles error for the adding
 *		node to the stack
 *@stack: pointer to the head of the stack list
 *@line_number: line index of file
 *@arg: argument from the monty file
 *
 */
void handle_add(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int n = add(stack);

	if (n == 0)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); /* FIXME: free stack before exiting */
	}
}

/**
 *handle_nop - nop does nothin
 *@stack: pointer to the head of the stack list
 *@line_number: line index of file
 *@arg: argument from the monty file
 *
 */
void handle_nop(stack_t **stack __attribute__((unused)),
		__attribute__((unused)) unsigned int line_number,
		__attribute__((unused)) void *arg)
{}
