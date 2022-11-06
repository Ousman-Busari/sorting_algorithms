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
	listint_t *current, *hole, *prv;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		hole = current;
		while (hole->prev && hole->prev->n > hole->n)
		{
			prv = hole->prev;
			if (hole->next)
				hole->next->prev = prv;
			if (prv->prev)
				prv->prev->next = hole;
			else
				*list = hole;
			prv->next = hole->next;
			hole->prev = prv->prev;
			hole->next = prv;
			prv->prev = hole;

			print_list(*list);
		}
		current = current->next;
	}
}
