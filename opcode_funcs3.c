#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * divide - divides the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void divide(stack_t **stack, unsigned int line_number)
{
	if (stack_with_less_than_two_elements(*stack))
	{
		div_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n == 0)
	{
		division_by_zero_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n /= (*stack)->n;

	pop(stack, line_number);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack_with_less_than_two_elements(*stack))
	{
		mul_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n *= (*stack)->n;

	pop(stack, line_number);
}
