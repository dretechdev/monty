#include "monty.h"
/**
 * fun_printTopElement - This function prints the top
 * @stackhead: The head of the stack
 * @lineNumber: The line number
 * Return: No return value
 */
void fun_printTopElement(stack_t **stackhead, unsigned int lineNumber)
{
	if (*stackhead == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		cleanAndExit(*stackhead);
	}
	printf("%d\n", (*stackhead)->n);
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
