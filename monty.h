#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#define UNK "L%u: unknown instruction %s\n"
#define DT_INIT {NULL, NULL, NULL, NULL, 0}

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments - structure of arguments from main
 * @av: name of the file from the command line
 * @ac: number of arguments from main
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct arguments
{
	char *av;
	int ac;
	unsigned int line_number;
} arguments_t;

/**
 * struct data_str - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_str
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_str_t;

typedef stack_t dlistint_t;
extern data_str_t data;

size_t dlstintlen(const dlistint_t *head);
dlistint_t *insnode_int(dlistint_t **head, const int num);
size_t prdlist_int(const dlistint_t *head);
int deldnot_at_pos(dlistint_t **head, unsigned int index);
dlistint_t *getnodint_at_pos(dlistint_t *head, unsigned int index);
dlistint_t *ins_dnode_at_pos(dlistint_t **head, unsigned int index, int num);
dlistint_t *ins_node_at_end(dlistint_t **head, const int num);
void emptydlistint(dlistint_t *head);
void exec_monty(arguments_t *arguments);
void (*oper_fnc(char **line))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int ln_n);
void pall(stack_t **stack, unsigned int ln_n);
void pint(stack_t **stack, unsigned int ln_n);
void pop(stack_t **stack, unsigned int ln_n);
void swap(stack_t **stack, unsigned int ln_n);
void add(stack_t **stack, unsigned int ln_n);
void nop(stack_t **stack, unsigned int ln_n);
void sub(stack_t **stack, unsigned int ln_n);
void _div(stack_t **stack, unsigned int ln_n);
void mul(stack_t **stack, unsigned int ln_n);
void mod(stack_t **stack, unsigned int ln_n);
void rotl(stack_t **stack, unsigned int ln_n);
void rotr(stack_t **stack, unsigned int ln_n);
void stack_fnc(stack_t **stack, unsigned int ln_n);
void queue_func(stack_t **stack, unsigned int ln_n);
void pchar(stack_t **stack, unsigned int ln_n);
void pstr(stack_t **stack, unsigned int ln_n);
int wordlen(char *s);
char **_strtow(char *s);
void free_a(char **arguments);
void free_everything(int every);

#endif /* MONTY_H */
