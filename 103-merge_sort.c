#include "sort.h"

void merge(int *left_array, int *right_array, int *array, size_t size);
/**
 * merge_sort - sorts an array of integers in ascending order using
 *              the merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t left_count, i;
	int *left_array, *right_array;

	if (!array || size < 2)
		return;

	left_count = size / 2;
	left_array = malloc(sizeof(int) * left_count);
	if (!left_array)
		return;
	for (i = 0; i < left_count; i++)
		left_array[i] = array[i];
	right_array = array + left_count;
	merge_sort(left_array, left_count);
	merge_sort(right_array, size - left_count);
	merge(left_array, right_array, array, size);
	free(left_array);
}

/**
 * merge - merges to sorted array of integers into one
 * @left_array: the first/left array
 * @right_array: the second/right array
 * @array: the array to merge them into
 * @size: size of array
 *
 * Return: Nothing
 */
void merge(int *left_array, int *right_array, int *array, size_t size)
{
	size_t left_count, right_count, i = 0, j = 0, k = 0;

	left_count = size / 2;
	right_count = size - left_count;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, left_count);

	printf("[right]: ");
	print_array(right_array, right_count);

	while (i < left_count && j < right_count)
	{
		if (left_array[i] < right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	while (i < left_count)
		array[k++] = left_array[i++];
	while (j < right_count)
		array[k++] = right_array[j++];

	printf("[Done]: ");
	print_array(array, size);
}
