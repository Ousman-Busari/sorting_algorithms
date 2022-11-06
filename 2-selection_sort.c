#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, i_min;
	int holder;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}
		if (i_min != i)
		{
			holder = array[i];
			array[i] = array[i_min];
			array[i_min] = holder;
			print_array(array, size);
		}
	}
}
