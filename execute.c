#include "monty.h"
/**
 * execute - This executes the opcode
 * @stack: This is the linked list to the head
 * @lineNum: This is the line counter
 * @file: This is the pointer to the monty file
 * @detail: The line content
 * Return: No return value
 */
int execute(char *detail, stack_t **stack, unsigned int lineNum, FILE *file)
{
	instruction_t opst[] = {{"push", fun_push}, {"pall", fun_pall},
		{"pint", fun_printTopElement},
		{"pop", fun_pop},
		{"swap", fun_swap},
		{"add", fun_addition},
		{"div", fun_division},
		{"mod", fun_modulus},
		{"pstr", fun_pstr},
		{"rotr", fun_rotr},
		{"pchar", fun_pchar},
		{"stack", set_stack_mode},
		{"queue", set_queue_mode},
		{"mul", fun_multiplication},
		{"sub", fun_subtraction},
		{"rotl", fun_rotl},
		{"nop", fun_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(detail, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, lineNum);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unkown instruction %s\n", lineNum, op);
		fclose(file);
		free(detail);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
