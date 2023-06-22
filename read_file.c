#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * read_file - read a file and execute commands.
 * @filename: the path to the file.
 * @stack: pointer point to the top of stack.
 *
 * Return: void.
 */
void read_file(char *filename, stack_t **stack)
{
	ssize_t length, close_check;
	unsigned int line_number = 1;
	size_t size = 0;
	char *line;
	void (*function)(stack_t **stack, unsigned int line_number);

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((length = getline(&buffer, &size, file)) != -1)
	{
		line = split_line(buffer, stack, line_number);
		if (line == NULL || line[0] == '#')
		{
			line_number++;
			continue;
		}
		function = get_function(line);
		if (function == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}
		function(stack, line_number);
		line_number++;
	}
	free(buffer);
	close_check = fclose(file);
	if (close_check == -1)
		exit(EXIT_FAILURE);
}
