#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_monty_line - Initializes a monty_line_t instance
 *
 * Return: 1 if success, 0 if failure
*/
int init_monty_line(void)
{
	/* Allocate memory to monty_line instance */
	monty_line = malloc(sizeof(monty_line_t));
	if (monty_line == NULL)
	{
		malloc_error();
		return (0);
	}

	monty_line->line_number = 0;
	monty_line->command = NULL;
	monty_line->argument = NULL;
	monty_line->status = EXIT_SUCCESS;

	return (1);
}
