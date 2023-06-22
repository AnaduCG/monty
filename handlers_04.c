#include "monty.h"

/**
 * handle_rotr - rotate the stack top element moved to last
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of the instruction
 */
void handle_rotr(stack_t **stack,
		unsigned int line_number __attribute__((unused)),
		void *arg __attribute__((unused)))
{
	rotr(stack);
}
