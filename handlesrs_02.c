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
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
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

/**
 * handle_sub - handle the opcode sub
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_sub(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int ret_val = sub(stack);

	if (ret_val == 0)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_div - handle the opcode div
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_div(stack_t **stack, unsigned int line_number,
		void *arg __attribute__((unused)))
{
	int ret_val = _div(stack);

	if (ret_val != 1)
	{
		if (ret_val == 0)
			fprintf(stderr, "L%d: can't div, stack too short\n",
					line_number);
		else if (ret_val == -1)
			fprintf(stderr, "L%d: division by zero\n",
					line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
