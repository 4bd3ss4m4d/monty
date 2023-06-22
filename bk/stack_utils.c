#include "monty.h"

/**
 * oper_push - Push an integer onto a stack
 * @stack: Pointer to the stack
 * @ln_n: Line number
 *
 * Return: None
 */
void oper_push(stack_t **stack, unsigned int ln_n)
{
	int num;
	stack_t *new_stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", ln_n);
		exit(EXIT_FAILURE);
	}

	if (oprnd == NULL || _atoi(oprnd, &num) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_n);
		exit(EXIT_FAILURE);
	}

	new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}
	new_stack->next = *stack;
	new_stack->prev = NULL;
	new_stack->n = num;

	if (*stack)
	{
		(*stack)->prev = new_stack;
	}
	*stack = new_stack;
}

/**
 * oper_pall - Print all elements in the stack
 * @stack: Pointer to the stack
 * @ln_n: Line number
 *
 * Return: None
 */
void oper_pall(stack_t **stack, unsigned int ln_n)
{
	stack_t *temporary = *stack;

	(void)ln_n;
	while (temporary)
	{
		printf("%d\n", temporary->n);
		temporary = temporary->next;
	}
}

/**
 * oper_pint - Print the top element of the stack
 * @stack: Pointer to the stack
 * @ln_n: Line number
 *
 * Return: None
 */
void oper_pint(stack_t **stack, unsigned int ln_n)
{
	stack_t *temporary;

	(void)ln_n;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_n);
		exit(EXIT_FAILURE);
	}
	temporary = *stack;
	printf("%d\n", temporary->n);
}
