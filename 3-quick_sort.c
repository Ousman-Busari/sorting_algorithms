#include "sort.h"

int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the quick sort algorithm
 * @array: the array of integers to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - sorts an array of integers within a
 *               certain range of index
 * @array: the array to be sorted
 * @size: size of the array
 * @start: index of where to start the sorting
 * @end: index of where to end the sorting
 *
 * Return: Nothing
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int p_index;

	if (start < end)
	{
		p_index = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, p_index - 1);
		lomuto_sort(array, size, p_index + 1, end);
	}
}

/**
 * lomuto_partition - uses the last element of an array as the pivot for
 *                    partitioning an array withi a range of index
 * @array: array of integers to be partitioned
 * @size: size of the array
 * @start: index where to start the partitioning
 * @end: where to end the partioning
 *
 * Return: right index partiton element use as pivot
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int i, holder, p_index = start;
	int pivot;

	pivot = array[end];
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (array[i] < array[p_index])
			{
				holder = array[i];
				array[i] = array[p_index];
				array[p_index] = holder;
				print_array(array, size);
			}
			p_index++;
		}
	}

	if (array[p_index] > pivot)
	{
		holder = array[p_index];
		array[p_index] = pivot;
		array[end] = holder;
		print_array(array, size);
	}
	return (p_index);
}
