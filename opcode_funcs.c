#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * empty_instruction - Does nothing.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
*/
void empty_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * comment_instruction - Does nothing.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
 *
*/
void comment_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * push - Pushes an element to the stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = create_node();

	/* If malloc() fails to allocate memory */
	if (new_node == NULL)
	{
		malloc_error();
		return;
	}

	/* If push's argument is not a number */
	if (!_isint(monty_line->argument))
	{
		free(new_node);
		push_arg_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	new_node->n = atoi(monty_line->argument);

	push_front(stack, new_node);
}

/**
 * pall - Prints all the values on the stack, starting from the top of the
 *	stack.
 * @stack: The stack.
 * @line_number: The line number.
 *
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
