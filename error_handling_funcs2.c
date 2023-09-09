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
