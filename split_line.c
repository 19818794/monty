#include "monty.h"

/**
 * split_line - splits line to opcode and argument.
 * @line: the line to be splitted.
 * @line_number: the line number on which the opcode appears.
 *
 * Return: opcode ot NULL if it fails.
 */
char *split_line(char *line, unsigned int line_number)
{
	char *push = "push", *opcode, *arg,
	     *sstack = "stack", *queue = "queue";

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
	else if (strcmp(opcode, sstack) == 0)
		flag_stack_queue = 1;
	else if (strcmp(opcode, queue) == 0)
		flag_stack_queue = 0;
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
