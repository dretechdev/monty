#include "monty.h"
/**
 * fun_multiplication - This multiplies two elements of the stack
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: This has no return value
 */
void fun_multiplication(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int tempo, length = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tempo = h->next->n * h->n;
	h->next->n = tempo;
	*head = h->next;
	free(h);
}
