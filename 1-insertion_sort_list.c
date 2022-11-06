#include "sort.h"

/**
 * insertion_sort_list - sorts the doubly linked list of integers using
 *                       the insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node, *hole;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (node->next != NULL)
	{
		hole = node->next;
		if (node->n > hole->n)
		{
			swap(node, hole);
			if (hole->prev == NULL)
				*list = hole;

			print_list(*list);

			while (hole->prev != NULL)
			{
				tmp = hole->prev;
				if (tmp->n > hole->n)
				{
					swap(tmp, hole);
					if (hole->prev == NULL)
						*list = hole;

					print_list(*list);
				}
				else
					break;
			}

			continue;
		}
		node = node->next;
	}
}

/**
 * swap - swaps two nodes of a doubly linked list
 * @node_1: the first node
 * @node_2: the second node
 *
 * Return: Nothing
 */
void swap(listint_t *node_1, listint_t *node_2)
{
	listint_t *tmp;

	tmp = node_1->next;
	node_1->next = node_2->next;
	node_2->next = tmp;

	if (node_1->next != NULL)
		node_1->next->prev = node_1;
	if (node_2->next != NULL)
		node_2->next->prev = node_2;

	tmp = node_1->prev;
	node_1->prev = node_2->prev;
	node_2->prev = tmp;

	if (node_1->prev != NULL)
		node_1->prev->next = node_1;
	if (node_2->prev != NULL)
		node_2->prev->next = node_2;
}
