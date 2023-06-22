#include "monty.h"

/**
 * handle_mul - handle the opcode mul
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_mul(stack_t **stack, unsigned int line_number, void *arg)
{
	int ret_val = mul(stack);

	((void)arg);
	if (ret_val == 0)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_mod - handle the opcode mod
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_mod(stack_t **stack, unsigned int line_number, void *arg)
{
	int ret_val = mod(stack);

	((void)arg);
	((void)arg);
	if (ret_val != 1)
	{
		if (ret_val == 0)
			fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		else if (ret_val == -1)
			fprintf(stderr, "L%d: division by zero\n",
				line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_pchar - handle the opcode pchar
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_pchar(stack_t **stack, unsigned int line_number, void *arg)
{
	int ret_val = pchar(*stack);

	((void)arg);
	((void)arg);
	if (ret_val != 1)
	{
		if (ret_val == 0)
			fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		else if (ret_val == -1)
			fprintf(stderr,
				"L%d: can't pchar, value out of range\n",
				line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_pstr - handle the opcode pstr
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of instruction
 */
void handle_pstr(stack_t **stack, unsigned int line_number, void *arg)
{
	((void)line_number);
	((void)arg);
	pstr(*stack);
}

/**
 * handle_rotl - rotate the stack top element moved to last
 * @stack: pointer to pointer to stack
 * @line_number: file index
 * @arg: argument of the instruction
 */
void handle_rotl(stack_t **stack, unsigned int line_number, void *arg)
{
	((void)line_number);
	((void)arg);
	rotl(stack);
}
