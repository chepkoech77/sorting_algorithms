#include "sort.h"
/**
 * swap - swaps the elements
 * @a: first int
 * @b: second int
 *
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - performs selectionsort
 * @array: array
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		size_t min = i;

		for (j = i + i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
