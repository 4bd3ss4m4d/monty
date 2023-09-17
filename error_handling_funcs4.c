#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar_not_ascii_error - prints error message when value is not ascii
 * to perform pchar
 *
 * Return: void
*/
void pchar_not_ascii_error(void)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n",
		monty_line->line_number);
}
