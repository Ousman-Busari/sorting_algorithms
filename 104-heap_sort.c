#include "sort.h"

void swap(int *a, int *b);
void heapify_max(int *array, size_t size, size_t root, size_t i);

/**
 * heap_sort - sorts an array on integers in ascending order
 *              using the heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify_max(array, size, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify_max(array, size, i, 0);
	}
}

/**
 * swap - swaps two elements in an array
 * @a: address of the first element in the array
 * @b: address of the second element in the array
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify_max - turns an binary tree into a binary heap
 * @array: the array representation of the binary tree
 * @size: size of the array
 * @root: root of the tree
 * @i: index of the root node in the array
 *
 * Return: Nothing
 */
void heapify_max(int *array, size_t size, size_t root, size_t i)
{
	size_t largest, left, right;

	largest = i;
	left = i * 2 + 1;
	right = i * 2 + 2;

	if (left < root && array[left] > array[largest])
		largest = left;

	if (right < root && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap((array + i), (array + largest));
		print_array(array, size);
		heapify_max(array, size, root, largest);
	}
}
