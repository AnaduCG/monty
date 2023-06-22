#include "monty.h"

/**
 *main - entry point in all C programming
 *@argc: gets the number of arguments passed
 *@argv: arguments passed
 *Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned int line = 1;
	char buffer[256];
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
		_error("USAGE: monty file\n");
	/* opening file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Read lines from the file */
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (ferror(file))/* Handling read error */
		{
			fprintf(stderr, "Error reading file\n");
			fclose(file);
			exit(EXIT_FAILURE);
		}
		_to_arr(buffer, line, &stack);
		line++;
	}

	fclose(file);
	free_stack(&stack);
	return (0);
}
