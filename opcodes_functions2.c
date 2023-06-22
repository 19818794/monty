#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	size_t sum;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}
/**
 * _nop - doesn’t do anything.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _nop(stack_t **stack __attribute__ ((unused)),
	unsigned int line_number __attribute__ ((unused)))
{
	;
}
/**
 * _sub: subtracts the top element of the stack from the second top element
 * of the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int sub;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = sub;
}
/**
 * _div - divides the second top element of the stack by the top element
 * of the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int div;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n /= div;
}
