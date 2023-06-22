#include "monty.h"

/**
 * free_list - frees a list.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_list(stack_t *head)
{
	stack_t *ptr;

	while (head != NULL)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
