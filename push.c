#include "monty.h"
/**
 * fun_push - This adds a node to the stack
 * @head: The head of the stack
 * @counter: The line number
 * Return: No return value
 */
void fun_push(stack_t **head, unsigned int counter)
{
	int n;
	int index = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > 57 || bus.arg[index] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		pushnode(head, n);
	else
		pushqueue(head, n);
}
