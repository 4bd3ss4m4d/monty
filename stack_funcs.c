#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_node - Creates a new node.
 *
 * Return: A pointer to the new node, otherwise NULL.
*/
stack_t *create_node(void)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = 0;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/**
 * push_front - Adds a new node to the beginning of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 * @new_node: A pointer to the new node.
 *
 * Return: void
*/
void push_front(stack_t **head, stack_t *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}

/**
 * is_empty_stack - Checks if a stack_t list is empty.
 * @stack: A pointer to the head of the stack_t list.
 *
 * Return: 1 if the stack_t list is empty, otherwise 0.
*/
bool is_empty_stack(stack_t *stack)
{
	return (stack == NULL);
}

/**
 * pop_front - Removes the first node of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 *
 * Return: void
*/
void pop_front(stack_t **head)
{
	stack_t *temp;

	if (is_empty_stack(*head))
	{
		return;
	}

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * stack_with_less_than_two_elements - Checks if a stack_t list has less than
 * two elements.
 * @stack: A pointer to the head of the stack_t list.
 *
 * Return: 1 if the stack_t list has less than two elements, otherwise 0.
*/
bool stack_with_less_than_two_elements(stack_t *stack)
{
	return (stack == NULL || stack->next == NULL);
}
