#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *top, *second_top;

	if (stack_with_less_than_two_elements(*stack))
	{
		return;
	}

	top = *stack, second_top = (*stack)->next;

	top->next = NULL;
	second_top->prev = NULL;
	*stack = second_top;

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = top;
	top->prev = current;

	(void)line_number;
}
