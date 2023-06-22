#include "monty.h"

/**
 * oper_fnc - selects the right function
 * @line: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*oper_fnc(char **line))(stack_t **, unsigned int)
{
	instruction_t all_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"swap", swap},
		{"mod", mod},
		{"pchar", pchar},
		{"pint", pint},
		{"pop", pop},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_fnc},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"queue", queue_func},
		{NULL, NULL}
	};
	int i, length = 17;

	for (i = 0; i < length; i++)
	{
		if (strcmp(all_funcs[i].opcode, line[0]) == 0)
		{
			return (all_funcs[i].f);
		}
	}
	return (NULL);
}
