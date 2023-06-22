#include "monty.h"

/**
 * queue_func - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void queue_func(stack_t **stack, unsigned int ln_n)
{
	(void)stack;
	(void)ln_n;
	data.qflag = 1;
}

/**
 * stack_fnc - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @ln_n: number of the line in the file
 */
void stack_fnc(stack_t **stack, unsigned int ln_n)
{
	(void)stack;
	(void)ln_n;
	data.qflag = 0;
}
