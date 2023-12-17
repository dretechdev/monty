#include "monty.h"
/**
 * fun_swap_stack - This adds the top two elements of the stack
 * @head: The head of the stack
 * @counter: The line number
 * Return: No return value
 */
void fun_swap_stack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, auxiliary;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	auxiliary = h->n;
	h->n = h->next->n;
	h->next->n = auxiliary;
}
