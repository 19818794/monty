#ifndef MONTY_H
#define MONTY_H

/*
 * Desc: header file containing all libraries,
 * global variables, structures and prototypes.
 */

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Global variables */
extern char *filename;
extern FILE *file;
extern int push_arg;
extern char *buffer;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
/* Main function */
void read_file(char *filename, stack_t **stack);
void free_list(stack_t *head);

/* Read function */
void (*get_function(char *line))(stack_t **stack, unsigned int line_number);

/* Split function */
char *split_line(char *line, stack_t **stack, unsigned int line_number);
int is_number(char *str);

/* opcodes functions */
void _push(stack_t **stack, unsigned int line_number __attribute__ ((unused)));
void _pall(stack_t **stack, unsigned int line_number __attribute__ ((unused)));
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack __attribute__ ((unused)),
		unsigned int line_number __attribute__ ((unused)));
void _sub(stack_t **stack, unsigned int line_number);

#endif
