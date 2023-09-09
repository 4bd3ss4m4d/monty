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
