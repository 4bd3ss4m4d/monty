#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (is_empty_stack(*stack))
	{
		pop_empty_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	pop_front(stack);

	(void)line_number;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack_with_less_than_two_elements(*stack))
	{
		swap_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	/* Swap the 1st and 2nd Node */
	temp = (*stack)->next->next;

	(*stack)->next->prev = NULL;
	(*stack)->next->next = (*stack);

	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp;

	(*stack) = (*stack)->prev;

	(void)line_number;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (stack_with_less_than_two_elements(*stack))
	{
		add_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element of
 *       the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_with_less_than_two_elements(*stack))
	{
		sub_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;

	pop(stack, line_number);
}
