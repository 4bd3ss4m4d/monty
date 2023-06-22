#include "monty.h"

/**
 * **_strtow - splits a string into words
 * @s: string to split
 *
 * Return: pointer to an array of strings (Success)
 *         or NULL (Error)
 */
char **_strtow(char *s)
{
	char **mtrx, *temporary;
	int i, k = 0, length = strlen(s), w = wordlen(s), c = 0, begin, finish;


	if (w == 0)
	{
		return (NULL);
	}
	mtrx = (char **) malloc((w + 1) * sizeof(char *));
	if (mtrx == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		if (isspace(s[i]) || s[i] == '\0' || s[i] == '\n')
		{
			if (c)
			{
				finish = i;
				temporary = (char *) malloc(sizeof(char) * (c + 1));
				if (temporary == NULL)
					return (NULL);
				while (begin < finish)
					*temporary++ = s[begin++];
				*temporary = '\0';
				mtrx[k] = temporary - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			begin = i;
	}
	mtrx[k] = NULL;
	return (mtrx);
}

/**
 * wordlen - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int wordlen(char *s)
{
	int flag = 0, c, word = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			flag = 1;
			word++;
		}
	}

	return (word);
}
