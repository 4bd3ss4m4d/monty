#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - adds a new node at the beginning of a stack_t list.
 * @stack: pointer to the head of the stack
 * @l_num: line number
 * @num: value to be added to the new node
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int l_num, char *num)
{
	int i;
	stack_t *new_st = NULL;

	if (num == NULL)
	{
		printf("L%d: usage: push integer\n", l_num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[0] == '-' && i == 0)
		{
			continue;
		}
		if (isdigit(num[i]) == 0)
		{
			printf("L%d: usage: push integer\n", l_num);
			exit(EXIT_FAILURE);
		}
	}
	new_st = malloc(sizeof(stack_t));
	if (new_st == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_st->n = atoi(num);
	new_st->prev = NULL;
	new_st->next = NULL;
	if (*stack != NULL)
	{
		new_st->next = *stack;
		(*stack)->prev = new_st;
	}
	*stack = new_st;
}

/**
 * pall - prints all the values on the stack, starting from the top of the
 *	  stack.
 * @stack: pointer to the head of the stack
 * @l_num: line number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))l_num)
{
	stack_t *curr = *stack;

	if (*stack == NULL || stack == NULL)
	{
		return;
	}

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
