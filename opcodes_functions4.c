#include "monty.h"

/**
 * _rotl - rotates the stack to the top.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element, *second_top_element;

	if (!stack || !*stack || !(*stack)->next || !line_number)
		return;
	top_element = *stack;
	second_top_element = top_element->next;
	while (top_element->next)
		top_element = top_element->next;
	top_element->next = *stack;
	(*stack)->prev = top_element;
	(*stack) = second_top_element;
	top_element->next->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * _rotr - rotates the stack to the bottom.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _rotr(stack_t **stack, unsigned int line_number __attribute__ ((unused)))
{
	stack_t *last_element, *second_last_element;

	if (!stack || !*stack || !(*stack)->next || !line_number)
		return;
	last_element = *stack;
	second_last_element = last_element;
	while (last_element->next)
	{
		second_last_element = last_element;
		last_element = last_element->next;
	}
	second_last_element->next = NULL;
	last_element->next = *stack;
	last_element->prev = NULL;
	(*stack)->prev = last_element;
	*stack = last_element;
}
/**
 * _stack -  sets the format of the data to a stack (LIFO). This is the default
 * behavior of the program.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _stack(stack_t **stack __attribute__ ((unused)),
		unsigned int line_number __attribute__ ((unused)))
{
	;
}
/**
 * _queue - sets the format of the data to a queue (FIFO).
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _queue(stack_t **stack __attribute__ ((unused)),
		unsigned int line_number __attribute__ ((unused)))
{
	;
}
