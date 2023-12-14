#include "monty.h"
/**
 * fun_push - This adds a node to the stack
 * @head: The head of the stack
 * @counter: The line number
 * Return: No return value
 */
void fun_push(stack_t **head, unsigned int counter)
{
	int a;
	int index = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;

		for (; bus.arg[index] != '\0'; b++)
		{
			if (bus.arg[index] > 57 || bus.arg[index] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			cleanAndExit(*head);
		}
	}
	else
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			cleanAndExit(*head);
		}
	a = atoi(bus.arg);

	if (bus.lifi == 0)
		pushnode(head, a);
	else
		addqueue(head, a);
}

/**
 * cleanAndExit - Cleans up and exits with failure status
 * @stackhead: The stack head
 * Return: No return value
 */
void cleanAndExit(stack_t *stackhead)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(head);
	exit(EXIT_FAILURE);
}
