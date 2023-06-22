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
