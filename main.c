#include "monty.h"

/**
 * main - Entry point of the Monty interpreter program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: Always returns 0 on successful execution
 */
int main(int argc, char *argv[])
{
	size_t sizeofbuffer = 1024, count = 0;
	ssize_t gline;
	stack_t *hd = NULL;
	char *tmp, *s = NULL, *arrayop[2];
	void (*operfnc)(stack_t **stack, unsigned int ln_n);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		gline = getline(&s, &sizeofbuffer, file);
		if (gline == -1)
			break;
		count++;
		arrayop[0] = strtok(s, "\n ");
		if (arrayop[0] == NULL)
			nop(&hd, count);
		else if (strcmp("push", arrayop[0]) == 0)
		{
			tmp = strtok(NULL, "\n ");
			push(&hd, count, tmp);
		}
		else if (arrayop[0] != NULL && arrayop[0][0] != '#')
		{
			operfnc = go(arrayop[0], count, &hd);

			if (operfnc == NULL && count == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
				count, arrayop[0]), exit(EXIT_FAILURE);
			}
		operfnc(&hd, count);
		}
	}
	fclose(file), free(s), free_stack(hd);
	return (0);
}
