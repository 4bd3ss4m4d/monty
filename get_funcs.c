#include "monty.h"
#include <string.h>

/**
 * get_opcode_func - gets the opcode function
 * @opcode: the opcode
 *
 * Return: the opcode function
 */
void (*get_opcode_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t monty_instructions[] = {
		{"", empty_instruction},
		{"#", comment_instruction},
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}};
	int i;

	for (i = 0; monty_instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, monty_instructions[i].opcode) == 0)
		{
			return (monty_instructions[i].f);
		}
	}

	invalid_opc_error();
	return (NULL);
}
