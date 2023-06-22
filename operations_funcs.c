#include "monty.h"


/**
 * mul - Multiplies the second element of the stack with the top element
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with the operation
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln_n);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n *= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * mod - Computes the modulus of the second element by the top elementi
 *of the stack
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with the operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n %= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with the operation
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n += one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * _div - Divides the second element of the stack by the top element
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with the operation
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_n);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n /= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}

/**
 * sub - Subtracts the top element of the stack from the second element
 * @stack: Pointer to the top of the stack
 * @ln_n: Line number associated with the operation
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int ln_n)
{
	stack_t *one, *two;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_n);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		one = *stack;
		two = one->next;
		two->n -= one->n;
		*stack = two;
		(*stack)->prev = NULL;
		free(one);
	}
}
