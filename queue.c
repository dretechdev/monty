#include "monty.h"
/**
 * set_queue_mode - This prints the top
 * @head: This is the stack head
 * @counter: This is the line number
 * Return: No return value
 */
void set_queue_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * pushqueue - This add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return value
 */
void pushqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
