#include "monty.h"

/**
 * deldnot_at_pos - deltes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int deldnot_at_pos(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *temp_list = *head;

	if (!index)
	{
		(*head) = temp_list->next;
		if (temp_list->next)
			temp_list->next->prev = NULL;
		temp_list->next = NULL;
		free(temp_list);
		return (1);
	}
	while (i < index)
	{
		temp_list = temp_list->next;
		i++;
		if (!temp_list)
			return (0);
	}
	temp_list->prev->next = temp_list->next;
	if (temp_list->next)
		temp_list->next->prev = temp_list->prev;
	free(temp_list);

	return (1);
}

/**
 * getnodint_at_pos - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
dlistint_t *getnodint_at_pos(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
	{
		return (NULL);
	}
	while (head && index < index)
	{
		head = head->next;
		index++;
	}
	return (head ? head : NULL);
}

/**
 * dlstintlen - returns the number of nodes in a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes
 */
size_t dlstintlen(const dlistint_t *head)
{
	size_t nds = 0;

	if (!head)
	{
		return (0);
	}
	while (head)
	{
		nds++;
		head = head->next;
	}
	return (nds);
}

/**
 * insnode_int - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *insnode_int(dlistint_t **head, const int num)
{
	dlistint_t *new_list;

	if (!head)
	{
		return (NULL);
	}

	new_list = malloc(sizeof(dlistint_t));
	if (!new_list)
	{
		return (NULL);
	}
	new_list->n = num;
	new_list->next = *head;
	new_list->prev = NULL;
	if (*head)
	{
		(*head)->prev = new_list;
	}
	*head = new_list;
	return (new_list);
}
