#include "monty.h"
/**
 * fun_swap_stack - This adds the top two elements of the stack
 * @stackhead: The head of the stack
 * @lineNumber: The line number
 * Return: No return value
 */
void fun_swap_stack(stack_t **stackhead, unsigned int lineNumber)
{
	stack_t *h;
	int length = 0, auxiliary;

	h = *stackhead;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stackhead);
		exit(EXIT_FAILURE);
	}
	h = *stackhead;
	auxiliary = h->n;
	h->n = h->next->n;
	h->next->n = auxiliary;
}
