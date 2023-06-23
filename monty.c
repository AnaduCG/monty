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
	char *_codes[16] = {"pall", "pint", "pop", "swap", "add", "nop", "sub",
		"div", "mul", "mod", "pchar", "pstr", "rotl", "rotr", "stack", NULL};
	instruction_t opcodes[] = {{"push", handle_push}, {"pall", handle_pall},
		{"pint", handle_pint}, {"pop", handle_pop}, {"swap", handle_swap},
		{"add", handle_add}, {"nop", handle_nop}, {"nop", handle_nop},
		{"sub", handle_sub}, {"mul", handle_mul}, {"div", handle_div},
		{"mod", handle_mod}, {"pchar", handle_pchar}, {"pstr", handle_pstr},
		{"rotl", handle_rotl}, {"rotr", handle_rotr}, {"stack", handle_stack},
		{"queue", handle_queue}, {NULL, NULL}};
	int i = 0, j;
	char *arg = NULL;
	char *val = argv[0];

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, val) == 0)
		{
			if (argv[1])
				arg = _strdup(argv[1]);
			for (j = 0; _codes[j]; j++)
				if (strcmp(val, _codes[j]) == 0)
					free(arg);
			free(argv);
			opcodes[i].f(stack, line_number, arg);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, val);
	free(argv);
	free_stack(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
