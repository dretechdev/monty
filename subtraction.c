#include "monty.h"
/**
 * fun_subtraction - This subtracts two elements of the stack
 * @stackhead: This is the stack head
 * @lineNumber: This is the line number
 * Return: This has no return value
 */
void fun_subtraction(stack_t **stackhead, unsigned int lineNumber)
{
	stack_t *h;
	int tempo, the_node;

	h = *stackhead;
	for (the_node = 0; h != NULL; the_node++)
		h = h->next;
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		cleanAndExit(stackhead);
	}
	h = *stackhead;
	tempo = h->next->n - h->n;
	h->next->n = tempo;
	*stackhead = h->next;
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
	free_stack(stackhead);
	exit(EXIT_FAILURE);
}
