#include "monty.h"

/**
 * free_a - frees arrays of strings
 * @arguments: array of strings to free
 */
void free_a(char **arguments)
{
	int index;

	if (!arguments)
	{
		return;
	}

	for (index = 0; arguments[index]; index++)
	{
		free(arguments[index]);
	}

	free(arguments);
}

/**
 * free_everything - custom memory handling function
 * @every: flag to indicate what to free
 */
void free_everything(int every)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		free_a(data.words);
		data.words = NULL;
	}
	if (every)
	{
		if (data.stack)
		{
			emptydlistint(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
