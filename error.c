#include "monty.h"
/**
 *_error - function that prints error to
 *stderr and exits the program with status failure
 *
 *@str: error message to be printed
 */
void _error(char *str)
{
	write(2, str, strlen(str));
	fclose(file);
	exit(EXIT_FAILURE);
}
