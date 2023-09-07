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
