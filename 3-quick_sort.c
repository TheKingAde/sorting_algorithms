#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: starting index
 * @high: ending index
 *
 * Return: The partition index
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_helper - Helper function for quick_sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: Starting index
 * @high: Ending index
 */
void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);

		quick_sort_helper(array, size, low, pi - 1);
		quick_sort_helper(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, size, 0, size - 1);
}
