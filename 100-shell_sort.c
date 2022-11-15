#include "sort.h"

/**
 * shell_sort - sorts array of integers in ascending order
 *              using the knuth sequence
 * @array: the array of integers to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
