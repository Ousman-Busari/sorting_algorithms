#include "sort.h"

/**
 * bubble_sort - sorts an array of int in ascending order
 *               using bubble sort algorithm
 * @array: array of iintegers to be sorted
 * @size: size of the array
 *
 * Return: Notthing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, holder, flag;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				holder = array[j];
				array[j] = array[j + 1];
				array[j + 1] = holder;
				print_array((const int *) array, size);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
