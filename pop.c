#include "monty.h"
/**
 * fun_pop - This prints the top
 * @stackhead: This is the head of the stack
 * @lineNumber: This is the line number
 * Return: No return value
 */
void fun_pop(stack_t **stackhead, unsigned int lineNumber)
{
	stack_t *h;

	if (*stackhead == NULL)
	{
		fprintf(stderr, "L%d: can'tnpop an empty stack\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stackhead);
		exit(EXIT_FAILURE);
	}
	h = *stackhead;
	*stackhead = h->next;
	free(h);
}
