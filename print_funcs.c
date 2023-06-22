#include "monty.h"

/**
 * pchar - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void pchar(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	putchar(node->n);
	putchar('\n');
}

/**
 * pstr - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void pstr(stack_t **stack, unsigned int ln_n)
{
	stack_t *nd = *stack;

	(void)ln_n;
	if (!nd)
	{
		putchar('\n');
		return;
	}
	while (nd && nd->n != 0 && nd->n >= 0 && nd->n <= 127)
	{
		putchar(nd->n);
		nd = nd->next;
	}
	putchar('\n');
}

/**
 * pall - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void pall(stack_t **stack, unsigned int ln_n)
{
	(void)ln_n;
	if (*stack)
		prdlist_int(*stack);
}

/**
 * pint - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void pint(stack_t **stack, unsigned int ln_n)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
