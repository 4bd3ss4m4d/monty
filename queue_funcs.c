#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push_rear - pushes a node to the rear of the stack
 * @head: double pointer to the head of the stack
 * @new_node: the new node to push to the rear of the stack
 *
 * Return: void
*/
void push_rear(stack_t **head, stack_t *new_node)
{
	stack_t *last = *head;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;
}
