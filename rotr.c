#include "monty.h"
/**
 * fun_rotr - This opcode rotr rotates the stack to the bottom.
 * @head: The stack head
 * @counter: The line_number
 * Return: No return value
 */
void fun_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}