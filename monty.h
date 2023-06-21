#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>


/* Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, void *arg);
} instruction_t;

/* ========= function prototypes ======== */

/* Handling monty commands*/
void handle_push(stack_t **, unsigned int, void *);
void handle_pall(stack_t **, unsigned int, void *);
void handle_pint(stack_t **, unsigned int, void *);

/* Handling stack list */
int pint(stack_t *);
size_t pall(stack_t *);
void free_stack(stack_t **);
stack_t *push(stack_t **, int);

/* error handling */
void _error(char *str);

/* Handling file contents */
void _to_arr(char *str, unsigned int line_number);
void run_instruction(stack_t **, unsigned int, char **);

#endif /* MONTY_H */
