#include "monty.h"

/**
 * _isdigit - Checks if a string represents a valid positive integer
 * @s: Pointer to the string to be checked
 *
 * Return: 0 if the string represents a valid positive integer, 1 otherwise
 */
int _isdigit(char *s)
{

	int index = 0;

	if (s[index] == '-')
		index++;
	while (s[index] != '\0')
	{
		if (!isdigit(s[index]))
			return (1);
		index++;
	}

	return (0);
}

/**
 * rotr - Rotates the stack to the right, moving the top element to the bottom
 * @stack: Double pointer to the top of the stack
 * @ln_n: Line number associated with the rotr operation (unused)
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		finish->prev->next = NULL;
		finish->prev = NULL;
		finish->next = begin;
		begin->prev = finish;
		*stack = finish;
	}
}

/**
 * rotl - Rotates the stack to the left, moving the bottom element to the top
 * @stack: Double pointer to the top of the stack
 * @ln_n: Line number associated with the rotl operation (unused)
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int ln_n)
{
	stack_t *begin, *finish;

	(void)ln_n;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		begin = finish = *stack;
		while (finish->next)
			finish = finish->next;
		*stack = begin->next;
		finish->next = begin;
		begin->prev = finish;
		begin->next = NULL;
		(*stack)->prev = NULL;
	}
}
