#include "monty.h"
/**
 * fun_printTopElement - This function prints the top
 * @head: The head of the stack
 * @counter: The line number
 * Return: No return value
 */
void fun_printTopElement(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
