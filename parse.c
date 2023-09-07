#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - parses a line from a monty file
 * @line: the line to parse
 *
 * Return: 1 if success, 0 if failure
*/
void parse_line(char *line)
{
	/* Trim heading and leading whitespaces */
	strtrim(line);

	/* Check if line is empty or a comment */
	if (str_is_empty(line))
	{
		monty_line->command = strdup("");
	}
	else if (line[0] == '#')
	{
		monty_line->command = strdup("#");
	}
	else
	{
		tokenize(line);
	}
}

/**
 * tokenize - Tokenizes a string.
 * @line: The string to tokenize.
 *
 * Return: void
 */
void tokenize(char *line)
{
	/* Array of opcodes that require args */
	char *command, *arg, *opcodes_with_args[] = {"push", NULL};
	int i;

	command = strtok(line, " \t\a\b");
	monty_line->command = strdup(command);

	arg = strtok(NULL, " \t\a\b");

	for (i = 0; opcodes_with_args[i] != NULL; i++)
	{
		if (strcmp(monty_line->command, opcodes_with_args[i]) == 0)
		{
			if (arg == NULL)
			{
				monty_line->argument = strdup("");
			}
			else
			{
				monty_line->argument = strdup(arg);
			}
		}
	}
}
