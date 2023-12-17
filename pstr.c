#include "monty.h"
/**
 * fun_pstr - This function prints string starting
 * from the top of the stack, with a new line
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: No return value
 */
void fun_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
