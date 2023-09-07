#include <ctype.h>
#include "monty.h"
#include <stdbool.h>
#include <string.h>


/**
 * strtrim - Removes leading and trailing whitespace characters from a string.
 * @str: The string to trim.
 *
 * Return: void
 */
void strtrim(char *str)
{
	/* Remove leading whitespace characters */
	size_t i = 0, j, len;

	while (isspace(str[i]))
	{
		i++;
	}

	if (i > 0)
	{
		j = 0;
		while (str[i])
		{
			str[j++] = str[i++];
		}
		str[j] = '\0';
	}

	/* Remove leading whitespace characters */
	len = strlen(str);
	while (len > 0 && isspace((unsigned char)str[len - 1]))
	{
		len--;
	}
	str[len] = '\0';
}

/**
 * str_is_empty - Checks if a string is empty.
 * @line: The string to check.
 *
 * Return: true if the string is empty, otherwise false.
 */
int str_is_empty(char *line)
{
	return (line[0] == '\0');
}

/**
 * _isint - Checks if a string is an integer.
 * @str: The string to check.
 *
 * Return: true if the string is an integer, otherwise false.
*/
bool _isint(char *str)
{
	int i;

	if (str_is_empty(str))
	{
		return (false);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
		{
			continue;
		}
		else if (!isdigit(str[i]))
		{
			return (false);
		}
	}

	return (true);
}
