#include "monty.h"
/**
 * fun_pall - This function prints the stack
 * @head: This is the stack head
 * @counter: This wasn't used
 * Return: Has no return value
 */
void fun_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
