#include "monty.h"
#include <stdlib.h>

#define MIN_CHAR_VALUE 0
#define MAX_CHAR_VALUE 127

/**
 * fun_pchar - This function prints the character at the top
 * of a stack with a new line
 * @head: This is the head of the stack
 * @counter: This is the line number
 * Return: No return value
 */
void fun_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		cleanAndExit(*head);
	}

	if (h->n > MAX_CHAR_VALUE || h->n < MIN_CHAR_VALUE)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		cleanAndExit(*head);
	}
	printf("%c\n", h->n);
}
/**
 * cleanAndExit - Cleans up resources and exits with failure status
 * @head: The stack head
 * Return: No return value
 */
void cleanAndExit(stack_t *head)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}
