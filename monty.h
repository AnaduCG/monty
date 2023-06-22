#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

/* Global variables */
extern FILE *file;
extern int toggle;

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
void handle_swap(stack_t **, unsigned int, void *);
void handle_pop(stack_t **, unsigned int, void *);
void handle_add(stack_t **, unsigned int, void *);
void handle_nop(stack_t **, unsigned int, void *);
void handle_sub(stack_t **, unsigned int, void *);
void handle_div(stack_t **, unsigned int, void *);
void handle_mul(stack_t **, unsigned int, void *);
void handle_mod(stack_t **, unsigned int, void *);
void handle_pchar(stack_t **, unsigned int, void *);
void handle_pstr(stack_t **, unsigned int, void *);
void handle_rotl(stack_t **, unsigned int, void *);
void handle_rotr(stack_t **, unsigned int, void *);
void handle_stack(stack_t **, unsigned int, void *);
void handle_queue(stack_t **, unsigned int, void *);

/* Handling stack list */
int swap(stack_t **);
int pint(stack_t *);
int add(stack_t **);
int pop(stack_t **);
int sub(stack_t **);
int _div(stack_t **);
int mul(stack_t **);
int mod(stack_t **);
int pchar(stack_t *);
void pstr(stack_t *);
void rotl(stack_t **);
void rotr(stack_t **);
size_t pall(stack_t *);
stack_t *push(stack_t **, int);
stack_t *enqueue(stack_t **, int);
void free_stack(stack_t **);

/* error handling */
void _error(char *str);
char *_is_int(char *str);
int _isascii(int);

/* Handling file contents */
void _to_arr(char *, unsigned int, stack_t **);
void run_instruction(stack_t **, unsigned int, char **);
char *_strdup(const char *str);

#endif /* MONTY_H */
