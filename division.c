#include "monty.h"
/**
 * fun_division - This divides the top two elements of the stack
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: This has no return value
 */
void fun_division(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0;
	int aux;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't divide, stack is too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = (h->next->n) / (h->n);
	(h->next->n) = aux;
	*head = (h->next);
	free(h);
}
