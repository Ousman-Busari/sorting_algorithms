#include "sort.h"
void swap(listint_t **list, listint_t *a, listint_t *b);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 *                      ascending order using the cocktail algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp_prev, *tmp_next;
	listint_t *tmp_out = NULL, *tmp_in = NULL;
	int flag = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (flag)
	{
		flag = 0;
		while (tmp->next && tmp->next != tmp_out)
		{
			tmp_next = tmp->next;
			if (tmp->n > tmp_next->n)
			{
				swap(list, tmp, tmp_next);
				flag = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (!flag)
			break;

		tmp_out = tmp;
		tmp = tmp->prev;

		while (tmp->prev  && tmp->prev != tmp_in)
		{
			tmp_prev = tmp->prev;
			if (tmp->n < tmp_prev->n)
			{
				swap(list, tmp_prev, tmp);
				print_list(*list);
				flag = 1;
			}
			else
				tmp = tmp->prev;
		}
		tmp_in = tmp;
		tmp = tmp->next;
	}
}


/**
 * swap - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @tmp_prev: the node that comes first amoungt the node to be swapped
 * @tmp: the node that comes next
 *
 * Return: Nothing
 */
void swap(listint_t **list, listint_t *tmp_prev, listint_t *tmp)
{
	if (tmp->next)
		tmp->next->prev = tmp_prev;
	if (tmp_prev->prev)
		tmp_prev->prev->next = tmp;
	else
		*list = tmp;
	tmp_prev->next = tmp->next;
	tmp->prev = tmp_prev->prev;
	tmp_prev->prev = tmp;
	tmp->next = tmp_prev;
}
