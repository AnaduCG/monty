#include "monty.h"
#include <string.h>

/**
 * run_instruction - run each line of instruction in a bytecode
 * @stack: pointer to stack
 * @line_number: file index
 * @argv: array of arguments
 */
void run_instruction(stack_t **stack, unsigned int line_number, char **argv)
{
	instruction_t opcodes[] = {
	    {"push", handle_push},
	    {"pall", handle_pall},
	    {"pint", handle_pint},
	    {"pop", handle_pop},
	    {"swap", handle_swap},
	    {"add", handle_add},
	    {NULL, NULL}};
	int i = 0, exists = 0;

	while (opcodes[i].opcode != NULL)
	{
		/*
		 *printf("opcode->%s\narg->%s\n", argv[0], argv[1]);
		 *printf("opcode->%s\n", opcodes[i].opcode);
		 *printf("---\n");
		 */
		if (strcmp(opcodes[i].opcode, argv[0]) == 0)
		{ /* run the instruction */
			exists++;
			opcodes[i].f(stack, line_number, argv[1]);
		}
		i++;
	}
	if (exists == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, argv[0]);
		exit(EXIT_FAILURE);
	}
	/* FIXME: handle command not found */
}
