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
	    {"nop", handle_nop},
	    {"nop", handle_nop},
	    {"sub", handle_sub},
	    {"mul", handle_mul},
	    {"div", handle_div},
	    {"mod", handle_mod},
	    {"pchar", handle_pchar},
	    {"pstr", handle_pstr},
	    {"rotl", handle_rotl},
	    {"rotr", handle_rotr},
	    {NULL, NULL}};
	int i = 0;
	char *arg = NULL;

	while (opcodes[i].opcode != NULL)
	{
		/*
		 *printf("opcode->%s\narg->%s\n", argv[0], argv[1]);
		 *printf("opcode->%s\n", opcodes[i].opcode);
		 *printf("---\n");
		 */
		if (strcmp(opcodes[i].opcode, argv[0]) == 0)
		{
			if (argv[1] != NULL)
				arg = _strdup(argv[1]);
			free(argv);
			/* run the instruction */
			opcodes[i].f(stack, line_number, arg);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, argv[0]);
	free(argv);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
