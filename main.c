#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char *file_name;
	int exit_code;

	if (invalid_args_num(argc))
	{
		exit(usage_error());
	}

	file_name = argv[1];
	monty_file = fopen(file_name, "r");
	if (monty_file == NULL)
	{
		exit(file_open_error(file_name));
	}

	/* Run Monty Bytecode */
	exit_code = run_interpreter(monty_file);

	fclose(monty_file);

	return (exit_code);
}
