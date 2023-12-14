#include "monty.h"
/**
 * pushnode - This function adds node to the head of the stack
 * @head: This is the head of the stack we are working with
 * @n: This is the new value
 * Return: No return value
 */
void pushnode(stack_t **head, int n)
{
	stack_t *latest_node, *auxiliary;

	auxiliary = *head;
	latest_node = malloc(sizeof(stack_t));
	if (latest_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (auxiliary)
	{
		auxiliary->prev = latest_node;
	}
	latest_node->n = n;
	latest_node->next = *head;
	latest_node->prev = NULL;
	*head = latest_node;
}
