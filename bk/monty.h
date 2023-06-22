#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


/**monty errors defined*/
#define MONTY_ERROR_NONE 0
#define MONTY_ERROR_INVALID_OPCODE 1
#define MONTY_ERROR_PUSH_MISSING_ARG 2
#define MONTY_ERROR_PUSH_INVALID_ARG 3
#define MONTY_ERROR_PINT_EMPTY 4
#define MONTY_ERROR_POP_EMPTY 5


/**
 * struct monty_s - Monty interpreter structure
 * @save_ptr: Pointer to the saved position in a string during parsing
 * @line: Line number in the Monty source code
 * @token: Current token being processed
 * @mode: Mode of operation (e.g., interpreter or script execution)
 * @error: Error code indicating any encountered error during execution
 */
typedef struct monty_s
{
	char  *save_ptr;
	int line;
	char *token;
	int mode;
	int error;
} monty_t;

extern char *oprnd;

/**
 * struct command_s - line content and its number
 * @line: line content
 * @num: line number
 *
 * Description: stores line of the monty source code
 */
typedef struct command_s
{
	char *line;
	int num;
} line_t;

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
	void (*f)(stack_t **stack, unsigned int ln_n);
} instruction_t;

char **splt_ln(char *parsed_line);
void (*op_function(char *str))(stack_t**, unsigned int);
void empty_lin
void oper_pint(stack_t **stack, unsigned int ln_n);
es(line_t *parsed_lines);
void free_stack(stack_t *hd);
line_t *txt_toarr(const char *nameoffile);
void oper_pop(stack_t **stack, unsigned int ln_n);
void oper_swap(stack_t **stack, unsigned int ln_n);
void oper_push(stack_t **stack, unsigned int ln_n);
void oper_pall(stack_t **stack, unsigned int ln_n);
int _atoi(char *str, int *num);

#endif /* MONTY_H */
