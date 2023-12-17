#include "monty.h"
/**
 * fun_subtraction - This subtracts two elements of the stack
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: This has no return value
 */
void fun_subtraction(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int tempo, the_node;

	h = *head;
	for (the_node = 0; h != NULL; the_node++)
		h = h->next;
	if (the_node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tempo = h->next->n - h->n;
	h->next->n = tempo;
	*head = h->next;
	free(h);
}
