#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int mod;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n %= mod;
}
