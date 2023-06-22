#include "monty.h"

#define BUFSIZE 64
char *oprnd;

/**
 * main - Entry point of the Monty interpreter program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: Always returns 0 on successful execution
 */
int main(int argc, char const *argv[])
{
	char **command, *stok;
	int len;
	line_t *parsed_lines;
	stack_t *stack = NULL;
	void (*oper)(stack_t**, unsigned int);

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	parsed_lines = txt_toarr(argv[1]);
	if (parsed_lines == NULL)
		return (0);
	len = 0;
	while ((parsed_lines + len)->content != NULL)
	{
		stok = (parsed_lines + len)->content;
		command = splt_ln(stok);
		oprnd = command[1];
		oper = op_function(command[0]);
		if (oper == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", len + 1, command[0]);
			free(command);
			free_stack(stack);
			empty_lines(parsed_lines);
			exit(EXIT_FAILURE);
		}
		oper(&stack, len + 1);
		free(command);
		len++;
	}
	free_stack(stack);
	empty_lines(parsed_lines);
	return (0);
}
