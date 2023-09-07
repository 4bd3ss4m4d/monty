#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_monty_line - Frees a monty_line_t instance
 *
 * Return: void
*/
void free_monty_line(void)
{
	if (monty_line == NULL)
	{
		return;
	}

	if (monty_line->command != NULL)
	{
		free(monty_line->command);
		monty_line->command = NULL;
	}
	if (monty_line->argument != NULL)
	{
		free(monty_line->argument);
		monty_line->argument = NULL;
	}

	free(monty_line);
	monty_line = NULL;
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top of the stack
 *
 * Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
