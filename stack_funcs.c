#include "monty.h"

/**
 * nop - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void nop(stack_t **stack, unsigned int ln_n)
{
	(void)stack;
	(void)ln_n;
}

/**
 * pop - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void pop(stack_t **stack, unsigned int ln_n)
{
	stack_t *temporary = *stack;

	if (!temporary)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	deldnot_at_pos(stack, 0);
}

/**
 * swap - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void swap(stack_t **stack, unsigned int ln_n)
{
	int num;
	stack_t *temporary = *stack, *nd = NULL;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}

	temporary = getnodint_at_pos(*stack, 0);
	num = temporary->n;
	deldnot_at_pos(stack, 0);
	nd = ins_dnode_at_pos(stack, 1, num);
	if (!nd)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * push - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void push(stack_t **stack, unsigned int ln_n)
{
	int i, num = 0;
	stack_t *nw_stack;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", ln_n);
			free_everything(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
	{
		nw_stack = insnode_int(stack, num);
	}
	else if (data.qflag == 1)
	{
		nw_stack = ins_node_at_end(stack, num);
	}
	if (!nw_stack)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}
