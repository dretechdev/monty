#include "monty.h"
/**
 * fun_rotl - This rotates the stack to the top
 * @head: The head of the stack
 * @count: The line number
 * Return: No return value
 */
void fun_rotl(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temporary = *head, *auxil;

	if (*head == NULL || (*head)->next == NULL)
		return;
	auxil = (*head)->next;
	auxil->prev = NULL;
	while (temporary->next != NULL)
		temporary = temporary->next;
	temporary->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temporary;
	(*head) = auxil;
}
