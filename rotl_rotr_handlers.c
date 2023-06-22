#include "monty.h"

/**
 * rotl - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void rotl(stack_t **stack, unsigned int ln_n)
{
	int n  = 0;
	stack_t *temporary = *stack;

	(void)ln_n;

	if (*stack == NULL)
	{
		return;
	}
	temporary = getnodint_at_pos(*stack, 0);
	n = temporary->n;
	deldnot_at_pos(stack, 0);
	ins_node_at_end(stack, n);
}

/**
 * rotr - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void rotr(stack_t **stack, unsigned int ln_n)
{
	int len = dlstintlen(*stack), n = 0;
	stack_t *temporary = *stack;

	(void)ln_n;
	if (*stack == NULL)
	{
		return;
	}
	temporary = getnodint_at_pos(*stack, len - 1);
	n = temporary->n;
	deldnot_at_pos(stack, len - 1);
	insnode_int(stack, n);
}
