#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * div_short_stack_error - prints error message when stack is too short
 * to perform div
 *
 * Return: void
*/
void div_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't div, stack too short\n",
		monty_line->line_number);
}

/**
 * division_by_zero_error - prints error message when division by zero
 *
 * Return: void
*/
void division_by_zero_error(void)
{
	fprintf(stderr, "L%u: division by zero\n", monty_line->line_number);
}

/**
 * mul_short_stack_error - prints error message when stack is too short
 * to perform mul
 *
 * Return: void
*/
void mul_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n",
		monty_line->line_number);
}

/**
 * mod_short_stack_error - prints error message when stack is too short
 * to perform mod
 *
 * Return: void
*/
void mod_short_stack_error(void)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n",
		monty_line->line_number);
}
