#include "monty.h"
/**
 * fun_rotl - This rotates the stack to the top
 * @stackhead: The head of the stack
 * @lineN: The line number
 * Return: No return value
 */
void fun_rotl(stack_t **stackhead, __attribute__((unused)) unsigned int lineN)
{
	stack_t *temporary = *stackhead, auxil;

	if (*stackhead == NULL || (*stackhead)->next == NULL)
		return;
	auxil = (*stackhead)->next;
	auxil->prev = NULL;
	while (temporary->next != NULL)
		temporary = temporary->next;
	temporary->next = *stackhead;
	(*stackhead)->next = NULL;
	(*stackhead)->prev = temporary;
	(*stackhead) = auxil;
}
