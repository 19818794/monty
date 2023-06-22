#include "monty.h"

/**
 * _push -  pushes an element to the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number __attribute__ ((unused)))
{
	stack_t *ptr = malloc(sizeof(stack_t));

	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr->prev = NULL;
	ptr->n = push_arg;
	ptr->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = ptr;
	*stack = ptr;
}
/**
 * _pall - prints all the values on the stack, starting from
 * the top of the stack.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number __attribute__ ((unused)))
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}
