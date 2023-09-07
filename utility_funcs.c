#include "monty.h"
#include <stdbool.h>

/**
 * invalid_args_num - Checks if the number of arguments is invalid
 * @argc: Number of arguments
 *
 * Return: true if invalid, false otherwise
*/
bool invalid_args_num(int argc)
{
	return (argc != 2);
}

