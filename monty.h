#ifndef MONTY_H
#define MONTY_H

/* Include Libraries */
#include <stdbool.h>
#include <stdio.h>

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

/**
 * struct monty_line_s - struct for monty file line
 * @line_number: the line number in the monty file
 * @command: the opcode command
 * @argument: the argument for the command
 * @status: the status of the command (1 if success, 0 if failure)
 *
 * Description: struct for monty file line. It holds monty line context
 *             information.
*/
typedef struct monty_line_s
{
	unsigned int line_number;
	char *command;
	char *argument;
	int status;
} monty_line_t;

/* Declare External Variable */
extern monty_line_t *monty_line;

/* Parse Funcs */
int init_monty_line(void);
void parse_line(char *line);
void tokenize(char *line);

/* Utility Funcs */
bool invalid_args_num(int argc);

/* Error Handling Funcs */
int usage_error(void);
int file_open_error(char *filename);
void malloc_error(void);
void invalid_opc_error(void);
void push_arg_error(void);
void pint_empty_stack_error(void);
void pop_empty_stack_error(void);
void swap_short_stack_error(void);
void add_short_stack_error(void);
void sub_short_stack_error(void);
void div_short_stack_error(void);
void division_by_zero_error(void);

/* Interpreter Funcs */
int run_interpreter(FILE *monty_file);

/* Memory Handling Funcs */
void free_monty_line(void);
void free_stack(stack_t **head);

/* String Funcs */
void strtrim(char *str);
int str_is_empty(char *line);
bool _isint(char *str);

/* Get Opcodes Funcs */
void (*get_opcode_func(char *opcode))(stack_t **, unsigned int);

/* Opcode Funcs */
void empty_instruction(stack_t **stack, unsigned int line_number);
void comment_instruction(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);

/* Stack Funcs */
stack_t *create_node(void);
void push_front(stack_t **head, stack_t *new_node);
bool is_empty_stack(stack_t *stack);
void pop_front(stack_t **head);
bool stack_with_less_than_two_elements(stack_t *stack);

#endif /* MONTY_H */
