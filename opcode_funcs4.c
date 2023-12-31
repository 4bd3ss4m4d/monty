#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *top, *second_top;

	if (stack_with_less_than_two_elements(*stack))
	{
		return;
	}

	top = *stack, second_top = (*stack)->next;

	top->next = NULL;
	second_top->prev = NULL;
	*stack = second_top;

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = top;
	top->prev = current;

	(void)line_number;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	if (stack_with_less_than_two_elements(*stack))
	{
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->prev->next = NULL;

	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;

	(*stack) = last;

	(void)line_number;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void stack(stack_t **stack, unsigned int line_number)
{
	monty_line->mode = STACK;
	(void)stack;
	(void)line_number;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the opcode in the file
 *
 * Return: void
*/
void queue(stack_t **stack, unsigned int line_number)
{
	monty_line->mode = QUEUE;
	(void)stack;
	(void)line_number;
}
