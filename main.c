#include "monty.h"
/* bus_t bus = {NULL, NULL, NULL, 0}; */
/**
 * main_function - This is the monty code interpreter
 * @argc: The number of arguments
 * @argv: The monty file location
 * Return: 0 on success
 */
int main_function(int argc, char *argv[])
{
	char *detail;
	FILE *file;
	size_t actualSize = 0;
	ssize_t line_reader = 1;
	stack_t *stack = NULL;
	unsigned int lineNumber = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_reader > 0)
	{
		detail = NULL;
		line_reader = getline(&detail, &actualSize, file);
		bus.detail = detail;
		lineNumber++;
		if (line_reader > 0)
			execute(detail, &stack, lineNumber, file);
		free(detail);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
