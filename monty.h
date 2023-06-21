#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

/* Prototypes */
void run_instruction(stack_t **, unsigned int, char **);

void handle_push(stack_t **, unsigned int, void *);
void handle_pall(stack_t **, unsigned int, void *);
void handle_pint(stack_t **, unsigned int, void *);

stack_t *push(stack_t **, int);
size_t pall(stack_t *);
int pint(stack_t *);
void free_stack(stack_t **);

#endif /* MONTY_H */
