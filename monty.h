#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct opcode_s - opcode and its function
 * @opc: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct opcode_s
{
	char *opc;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern FILE *file;
FILE *file;

void _div(stack_t **stack, unsigned int ln_n);
void pint(stack_t **stack, unsigned int ln_n);
void pop(stack_t **stack, unsigned int ln_n);
void pchar(stack_t **stack, unsigned int ln_n);
void free_stack(stack_t *stack);
int _isdigit(char *s);
void mul(stack_t **stack, unsigned int ln_n);
void mod(stack_t **stack, unsigned int ln_n);
void rotl(stack_t **stack, unsigned int ln_n);
void (*operator_function)(stack_t **, unsigned int);
void swap(stack_t **stack, unsigned int ln_n);
void add(stack_t **stack, unsigned int ln_n);
void nop(stack_t **stack, unsigned int ln_n);
void rotr(stack_t **stack, unsigned int ln_n);
void pstr(stack_t **stack, unsigned int ln_n);
void sub(stack_t **stack, unsigned int ln_n);
void (*go(char *op_f, unsigned int l, stack_t **s))(stack_t**, unsigned int);
void push(stack_t **stack, unsigned int ln_n, char *tmp);
void pall(stack_t **stack, unsigned int ln_n);

#endif /* MONTY_H */

