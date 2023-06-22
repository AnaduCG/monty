#include "monty.h"

/**
 * handle_rotr - rotate the stack top element moved to last
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of the instruction
 */
void handle_rotr(stack_t **stack, unsigned int line_number, void *arg)
{
	((void)line_number);
	((void)arg);
	rotr(stack);
}

/**
 * handle_stack - switch to stack mode
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of the instruction
 */
void handle_stack(stack_t **stack __attribute__((unused)),
		__attribute__((unused)) unsigned int line_number,
		__attribute__((unused)) void *arg)
{
	toggle = 0;
}

/**
 * handle_queue - switch to queue mode
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of the instruction
 */
void handle_queue(stack_t **stack __attribute__((unused)),
		__attribute__((unused)) unsigned int line_number,
		__attribute__((unused)) void *arg)
{
	toggle = 1;
}
