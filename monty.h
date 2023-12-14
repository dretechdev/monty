#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


/* PROTOTYPES */
void cleanAndExit(stack_t *head);
char *get_next_token(char *content);
void fun_multiplication(stack_t **stackhead, unsigned int lineNumber);
void fun_division(stack_t **head, unsigned int counter);
void fun_modulus(stack_t **head, unsigned int counter);
void fun_pall(stack_t **head, unsigned int counter);
void fun_pstr(stack_t **head, unsigned int counter);
void fun_addition(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int lineNum, FILE *file);
void fun_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void fun_pchar(stack_t **head, unsigned int counter);
void fun_push(stack_t **head, unsigned int counter);
void set_stack_mode(stack_t **head, unsigned int counter);
void pushnode(stack_t **head, int n);
void fun_subtraction(stack_t **stackhead, unsigned int lineNumber);
void fun_pop(stack_t **stackhead, unsigned int lineNumber);
void fun_rotl(stack_t **stackhead, __attribute__((unused)) unsigned int lineN);
void fun_printTopElement(stack_t **stackhead, unsigned int lineNumber);
void fun_swap_stack(stack_t **stackhead, unsigned int lineNumber);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif
