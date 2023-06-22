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
