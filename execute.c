#include "monty.h"

/**
 * execute - This executes the opcode
 * @stack: This is the linked list to the head
 * @counter: This is the line counter
 * @file: This is the pointer to the monty file
 * @content: The line content
 * Return: No return value
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {{"push", fun_push}, {"pall", fun_pall},
		{"pint", fun_printTopElement},
		{"pop", fun_pop},
		{"swap", fun_swap_stack},
		{"add", fun_addition},
		{"nop", fun_nop},
		{"sub", fun_subtraction},
		{"div", fun_division},
		{"mul", fun_multiplication},
		{"mod", fun_modulus},
		{"pchar", fun_pchar},
		{"pstr", fun_pstr},
		{"rotl", fun_rotl},
		{"rotr", fun_rotr},
		{"queue", set_queue_mode},
		{"stack", set_stack_mode},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
