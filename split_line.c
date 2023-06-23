#include "monty.h"

/**
 * split_line - splits line to opcode and argument.
 * @line: the line to be splitted.
 * @stack: a list for the monty stack.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: opcode ot NULL if it fails.
 */
char *split_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *push = "push", *opcode, *arg;
	(void)stack;

	opcode = strtok(line, "\n ");
	if (opcode == NULL)
		return (NULL);
	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (is_number(arg) == 0 && arg != NULL)
			push_arg = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}

/**
 * is_number - checks if a string if is a number.
 * @str: the string to be checked.
 *
 * Return: 0 if it is a number,
 * otherwise 1.
 */
int is_number(char *str)
{
	size_t i;

	if (str == NULL)
		return (1);
	for (i = 0; str[i]; i++)
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}
