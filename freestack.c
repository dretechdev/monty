#include "monty.h"
/**
 * freestack - This function frees a doubly linked list
 * @head: This is the head of the stack
 */
void freestack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		stack_t *tempo = current->next;

		free(current);
		current = tempo;
	}
}
