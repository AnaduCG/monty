#include "monty.h"
/**
 *_error - unction that prints error to
 *stderr and exits the program with status failure
 *
 *@str: error message to be printed
 */
void _error(char *str)
{
	write(2, str, strlen(str));
	exit(EXIT_FAILURE);
}
