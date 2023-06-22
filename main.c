#include "monty.h"

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	arguments_t args;

	args.av = argv[1], args.ac = argc, args.line_number = 0;
	exec_monty(&args);
	return (EXIT_SUCCESS);
}
