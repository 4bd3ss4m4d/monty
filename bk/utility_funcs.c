#include "monty.h"

#define DELIM " \t\r\n\a"

/**
 * txt_toarr - Read lines from a file and store them in an array of
 *             line_t structs
 * @nameoffile: Name of the file to read
 *
 * Return: Pointer to the array of line_t structs on success, NULL on failure
 */
line_t *txt_toarr(const char *nameoffile)
{
	size_t len = 0;
	int numberline = 0;
	char *buff;
	FILE *fp;
	line_t *lines, *tmp;

	if (nameoffile == NULL)
		return (0);

	fp = fopen(nameoffile, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", nameoffile);
		exit(EXIT_FAILURE);
	}
	buff = NULL, lines = NULL;
	while (getline(&buff, &len, fp) != -1)
	{

		tmp = realloc(lines, sizeof(line_t) * (numberline + 2));
		if (tmp == NULL)
		{
			fclose(fp);
			return (0);
		}
		lines = tmp;

		(lines + numberline)->line = strdup(buff);
		(lines + numberline)->num = numberline;
		numberline++;
		tmp = lines;
	}
	free(buff);
	(lines + numberline)->line = NULL;
	fclose(fp);
	return (lines);
}

/**
 * splt_ln - Split a parsed line into tokens
 * @parsed_line: The parsed line to be split
 *
 * Return: A double pointer to char representing the array of tokens
 */
char **splt_ln(char *parsed_line)
{
	char **tkns = NULL, **temporary = NULL, *tkn = strtok(parsed_line, DELIM);
	int pos = 0;

	while (tkn != NULL)
	{
		temporary = realloc(tkns, sizeof(char *) * (pos + 2));
		if (temporary == NULL)
		{
			fprintf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		tkns = temporary;
		tkns[pos] = tkn;
		tkn = strtok(NULL, DELIM);
		pos++;
	}
	tkns[pos] = NULL;
	return (tkns);
}

/**
 * _atoi - Convert a string to an integer
 * @str: The string to be converted
 * @num: Pointer to store the converted integer
 *
 * Return: 0 on successful conversion, -1 otherwise
 */
int _atoi(char *str, int *num)
{
	int sg = 1, response = 0, fn, i;

	for (fn = 0; !(str[fn] >= 48 && str[fn] <= 57); fn++)
	{
		if (str[fn] == '-')
		{
			sg *= -1;
		}
	}
	for (i = fn; str[i] ; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			response *= 10;
			response += (str[i] - 48);
		}
		else
		{
			return (-1);
		}
	}
	*num = response * sg;
	(void)(num);
	return (0);
}

/**
 * op_function - Get the function corresponding to an opcode
 * @str: Opcode string
 *
 * Return: Function pointer corresponding to the opcode, or NULL if not found
 */
void (*op_function(char *str))(stack_t**, unsigned int)
{
	instruction_t operat[] = {
		{"pall", oper_pall},
		{"pint", oper_pint},
		{"push", oper_push},
		{NULL, NULL}
	};
	int index = 0;

	while (operat[index].opcode != NULL && strcmp((operat[index].opcode), str))
	{
		index++;
	}
	return (operat[index].f);
}

/**
 * mt_err - Print Monty interpreter error message
 * @mt: Pointer to the Monty interpreter structure
 *
 * Return: None
 */
void mt_err(monty_t *mt)
{
	switch (mt->error)
	{
		case MONTY_ERROR_INVALID_OPCODE:
			printf("L%d: unknow instruction %s\n", mt->line, mt->token);
			break;
		case MONTY_ERROR_PUSH_MISSING_ARG:
		case MONTY_ERROR_PUSH_INVALID_ARG:
			printf("L%d: usage push integer\n", mt->line);
			break;
		case MONTY_ERROR_POP_EMPTY:
			printf("L%d: can't pop an empty stack\n", mt->line);
			break;
		case MONTY_ERROR_PINT_EMPTY:
			printf("L%d: can't %s, stack empty\n", mt->line, mt->token);
			break;
		default:
			printf("L%d: unknown error\n", mt->line);
	}
}
