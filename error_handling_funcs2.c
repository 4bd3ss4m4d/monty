#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint_empty_stack_error - Prints an error message when pint is called on an
 *                          empty stack
 *
 * Return: void
*/
void pint_empty_stack_error(void)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", monty_line->line_number);
}

/**
 * pop_empty_stack_error - Prints an error message when pop is called on an
 *                         empty stack
 *
 * Return: void
*/
void pop_empty_stack_error(void)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", monty_line->line_number);
}

/**
 * swap_short_stack_error - Prints an error message when swap is called on a
 *                          stack with less than two elements
 *
 * Return: void
*/
void swap_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n",
		monty_line->line_number);
}

/**
 * add_short_stack_error - Prints an error message when add is called on a
 *                         stack with less than two elements
 *
 * Return: void
*/
void add_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't add, stack too short\n",
		monty_line->line_number);
}

/**
 * sub_short_stack_error - Prints an error message when sub is called on a
 *                         stack with less than two elements
 *
 * Return: void
*/
void sub_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n",
		monty_line->line_number);
}

