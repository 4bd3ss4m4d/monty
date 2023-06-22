#include "monty.h"

/**
 * mul - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void mul(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = NULL, *node_0 = getnodint_at_pos(*stack, 0);
	stack_t *node_1 = getnodint_at_pos(*stack, 1);
	int ml = 0;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	ml = node_1->n * node_0->n;
	deldnot_at_pos(stack, 0);
	deldnot_at_pos(stack, 0);
	node = insnode_int(stack, ml);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void mod(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = NULL, *node_0 = getnodint_at_pos(*stack, 0);
	stack_t *node_1 = getnodint_at_pos(*stack, 1);
	int md = 0;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}

	md = node_1->n % node_0->n;
	deldnot_at_pos(stack, 0);
	deldnot_at_pos(stack, 0);
	node = insnode_int(stack, md);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void sub(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = NULL, *node_0 = getnodint_at_pos(*stack, 0);
	stack_t *node_1 = getnodint_at_pos(*stack, 1);
	int sb = 0;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	sb = node_1->n - node_0->n;
	deldnot_at_pos(stack, 0);
	deldnot_at_pos(stack, 0);
	node = insnode_int(stack, sb);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void _div(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = NULL, *node_0 = getnodint_at_pos(*stack, 0);
	stack_t *node_1 = getnodint_at_pos(*stack, 1);
	int dv = 0;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}

	dv = node_1->n / node_0->n;
	deldnot_at_pos(stack, 0);
	deldnot_at_pos(stack, 0);
	node = insnode_int(stack, dv);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void add(stack_t **stack, unsigned int ln_n)
{
	stack_t *node = NULL, *node_0 = getnodint_at_pos(*stack, 0);
	stack_t *node_1 = getnodint_at_pos(*stack, 1);
	int sm = 0;

	if (dlstintlen(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", ln_n);
		free_everything(1);
		exit(EXIT_FAILURE);
	}
	sm = node_0->n + node_1->n;
	deldnot_at_pos(stack, 0);
	deldnot_at_pos(stack, 0);
	node = insnode_int(stack, sm);
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_everything(1);
		exit(EXIT_FAILURE);
	}
}
