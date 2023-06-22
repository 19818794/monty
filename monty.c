#include "monty.h"

char *filename;
FILE *file;
int push_arg;
char *buffer;

/**
 * main - Entry point.
 * @argc: number of arguments.
 * @argv: arguments.
 *
 * Description: main function for monty.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	read_file(filename, &stack);
	free_list(stack);

	return (0);
}
