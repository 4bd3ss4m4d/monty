#include "monty.h"

data_str_t data = DT_INIT;

/**
 * exec_monty - helper function for main function
 * @arguments: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void exec_monty(arguments_t *arguments)
{
	int get = 0;
	size_t len = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (arguments->ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(arguments->av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", arguments->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		arguments->line_number++;
		get = getline(&(data.line), &len, data.fptr);
		if (get < 0)
		{
			break;
		}
		data.words = _strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_everything(0);
			continue;
		}
		code_func = oper_fnc(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNK, arguments->line_number, data.words[0]);
			free_everything(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), arguments->line_number);
		free_everything(0);
	}
	free_everything(1);
}
