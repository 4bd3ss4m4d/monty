#include "monty.h"

/**
 * ins_node_at_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *ins_node_at_end(dlistint_t **head, const int num)
{
	dlistint_t *new_list, *temporary = *head;

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
	new_list->next = NULL;

	if (*head == NULL)
	{
		new_list->prev = NULL;
		*head = new_list;
		return (new_list);
	}

	while (temporary->next)
	{
		temporary = temporary->next;
	}

	temporary->next = new_list;
	new_list->prev = temporary;

	return (new_list);
}

/**
 * emptydlistint - frees a doubly linked list
 * @head: pointer to the list to free
 */
void emptydlistint(dlistint_t *head)
{
	dlistint_t *temporary;

	while (head)
	{
		temporary = head->next;
		free(head);
		head = temporary;
	}
}
/**
 * ins_dnode_at_pos - inserts a node at a given index
 *                    in a doubly linked list
 * @head: double pointer to the list
 * @index: index of the node to insert
 * @num: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *ins_dnode_at_pos(dlistint_t **head, unsigned int index, int num)
{
	dlistint_t *new_list, *temporary = *head;
	unsigned int i;

	if (index == 0)
	{
		return (insnode_int(head, num));
	}
	for (i = 0; temporary && i < index; i++)
	{
		if (i == index - 1)
		{
			if (temporary->next == NULL)
			{
				return (ins_node_at_end(head, num));
			}
			new_list = malloc(sizeof(dlistint_t));
			if (!new_list || !head)
			{
				return (NULL);
			}
			new_list->n = num;
			new_list->next = NULL;
			new_list->next = temporary->next;
			new_list->prev = temporary;
			temporary->next->prev = new_list;
			temporary->next = new_list;
			return (new_list);
		}
		else
		{
			temporary = temporary->next;
		}
	}
	return (NULL);
}

/**
 * prdlist_int - prints a doubly linked list
 * @head: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t prdlist_int(const dlistint_t *head)
{
	size_t nds = 0;

	if (!head)
	{
		return (0);
	}
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		nds++;
	}
	return (nds);
}
