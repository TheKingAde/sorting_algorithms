#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0, *count, *output;

	if (array == NULL || size < 2)
		return;
	/* Find the maximum element in the array */
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	/* Initialize count array with all zeros */
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/* Store count of each character */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	/*
	 * Change count[i] so that count[i] now contains actual
	 * position of this character in output array
	 */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/* Build the output character array */
	output = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/*
	 * Copy the output array to array so that array now
	 * contains sorted characters
	 */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
