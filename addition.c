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
	int length = 0, sum;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	sum = (h->n) + (h->next->n);
	h->next->n = sum;
	*head = h->next;
	free(h);
}
