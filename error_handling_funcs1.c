#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * usage_error - Prints an error message when the number of arguments is
 *               invalid
 *
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints an error message when a file can't be opened
 * @filename: The name of the file that can't be opened
 *
 * Return: EXIT_FAILURE
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints an error message when malloc fails
 *
 * Return: void
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * invalid_opc_error - Prints an error message when an invalid opcode is
 *		       encountered
 *
 * Return: void
 */
void invalid_opc_error(void)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			monty_line->line_number, monty_line->command);
}

/**
 * push_arg_error - Prints an error message when push is not followed by an
 *                  argument
 *
 * Return: void
 */
void push_arg_error(void)
{
	fprintf(stderr, "L%u: usage: push integer\n", monty_line->line_number);
}

