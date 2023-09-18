#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/* Define Global Variable */
monty_line_t *monty_line = NULL;

/**
 * run_interpreter - Runs the Monty Bytecode interpreter
 * @monty_file: The Monty Bytecode file
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int run_interpreter(FILE *monty_file)
{
	stack_t *head = NULL;
	char *line = NULL;
	size_t buffer_size = 0;
	unsigned int current_line = 0;
	int exit_code = EXIT_SUCCESS, current_mode = STACK;
	bool monty_line_initialized = false;

	while ((getline(&line, &buffer_size, monty_file)) != -1)
	{
		monty_line_initialized = init_monty_line(current_mode);
		if (!monty_line_initialized)
		{
			exit_code = EXIT_FAILURE;
			break;
		}
		monty_line->line_number = ++current_line;
		parse_line(line);
		if (get_opcode_func(monty_line->command) == NULL)
		{
			exit_code = EXIT_FAILURE;
			break;
		}

		get_opcode_func(monty_line->command)(&head, monty_line->line_number);
		if (monty_line->status == EXIT_FAILURE)
		{
			exit_code = EXIT_FAILURE;
			break;
		}
		if (monty_line->mode == QUEUE)
			current_mode = monty_line->mode;
		else if (monty_line->mode == STACK)
			current_mode = monty_line->mode;

		free_monty_line();
	}
	free(line);
	free_stack(&head);
	free_monty_line();
	return (exit_code);
}
