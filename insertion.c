#include "sort.h"

void swap(listint_t *a, listint_t *b);

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: the list to be sorted.
 *
 * Description: You are not allowed to modify the integer n of a node.
 * You have to swap the nodes themselves.
 * You’re expected to print the list after each time you swap two elements.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current, *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current->next != NULL)
	{
		node = current->next;
		if (current->n > node->n)
		{
			swap(current, node);
			if (node->prev == NULL)
				*list = node;

			print_list(*list);

			while (node->prev != NULL)
			{
				tmp = node->prev;
				if (tmp->n > node->n)
				{
					swap(tmp, node);
					if (node->prev == NULL)
						*list = node;

					print_list(*list);
				}
				else
					break;
			}

			continue;
		}
		current = current->next;
	}
}

/**
 * swap - swaps two nodes of a doubly linked list.
 * @a: the first node
 * @b: the second node
 */
void swap(listint_t *a, listint_t *b)
{
	listint_t *tmp;

	tmp = a->next;
	a->next = b->next;
	b->next = tmp;

	if (a->next != NULL)
		a->next->prev = a;
	if (b->next != NULL)
		b->next->prev = b;

	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;

	if (a->prev != NULL)
		a->prev->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
}
