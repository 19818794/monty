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
/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int value;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}
/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: void.
 */
void _pstr(stack_t **stack, unsigned int line_number __attribute__ ((unused)))
{
	stack_t *ptr = *stack;
	int ch;

	while (ptr != NULL)
	{
		ch = ptr->n;
		if (ch == 0 || _isalpha(ch) == 1)
			break;
		putchar(ch);
		ptr = ptr->next;
	}
	putchar('\n');
}
/**
 * _isalpha - checks if a number is a code ASCII of an alphabet.
 * @ch: the number to be checked.
 *
 * Return: 0 if it is an alphabet,
 * 1 otherwise.
 */
int _isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 0)
		return (0);
	return (1);
}
