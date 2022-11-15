#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count, k = 0, j, index, *output_array;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		index = array[i], ++count[index];
	for (j = 1; j <= k; j++)
		count[j] += count[j - 1];
	print_array(count, k + 1);
	output_array = malloc(sizeof(int) * size);
	if (!output_array)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		index = array[i];
		output_array[count[index] - 1] = array[i];
		--count[index];
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(count);
	free(output_array);
}
