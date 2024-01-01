#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	/* Start with the largest gap and work down to a gap of 1 */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
	;

	for (gap /= 3; gap > 0; gap /= 3)
	{
		/* Do a gapped insertion sort for this gap size */
		for (i = gap; i < size; i++)
		{
			/* Add array[i] to the elements that have been gap sorted */
			temp = array[i];

			/* Shift earlier gap-sorted elements up until the correct location */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			/* Put temp (the original array[i]) in its correct location */
			array[j] = temp;
		}

		print_array(array, size);
	}
}
