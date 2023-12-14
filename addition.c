#include "monty.h"
/**
 * fun_addition - This adds the top elements of the stack
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: This has no return value
 */
void fun_addition(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		cleanAndExit(*head);
	}

	int sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;

	stack_t *temporary = *head;
	*head = (*head)->next;
	free(temporary);
}
/**
 * cleanAndExit - Cleans up resources and exits with failure status
 * @head: The stack head
 * Return: no return value
 */
void cleanAndExit(stack_t *head)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}
