/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp;

	for (i = 0, i < size - 1; i++)
	{
		for (size_t j = 0; j < size -i - 1; j++)
		{
			/** if the current element is greater than the next **/
			if (array[j] > array[j + 1])
			{
				/** swap **/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/** print after the swap **/
				print_array(array, size);
			}
		}
	}
}
