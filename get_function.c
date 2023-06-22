#include "monty.h"

/**
 * get_function - gets a corresponding function based on the opcode given.
 * @str: the opcode.
 *
 * Return: a pointer to the corresponding function,
 * otherwise NULL if it fails.
 */
void (*get_function(char *str))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL},
	};

	for (i = 0; instruction[i].f != NULL &&
	strcmp(instruction[i].opcode, str) != 0; i++)
		;
	return (instruction[i].f);
}
