#include "monty.h"
/**
 * fun_multiplication - This multiplies two elements of the stack
 * @stackhead: This is the stack head
 * @lineNumber: This is the line number
 * Return: This has no return value
 */
void fun_multiplication(stack_t **stackhead, unsigned int lineNumber)
{
	stack_t *h;
	int tempo, length = 0;

	h = *stackhead;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		cleanAndExit(*stackhead);
	}
	h = *head;
	tempo = h->next->n * h->n;
	h->next->n = tempo;
	*head = h->next;
	free(h);
}

/**
 * cleanAndExit - Cleans up resources and exits with failure status
 * @stackhead: The Stack head
 * Return: No return value
 */
void cleanAndExit(stack_t *stackhead)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}
