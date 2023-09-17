#include <ctype.h>
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

/**
 * mod - computes the modulus of the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack_with_less_than_two_elements(*stack))
	{
		mod_short_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n == 0)
	{
		division_by_zero_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n %= (*stack)->n;

	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (is_empty_stack(*stack))
	{
		pchar_empty_stack_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	if (!isascii((*stack)->n))
	{
		pchar_not_ascii_error();
		monty_line->status = EXIT_FAILURE;
		return;
	}

	printf("%c\n", (*stack)->n);

	(void)line_number;
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && isascii(current->n) && current->n != 0)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");

	(void)line_number;
}
