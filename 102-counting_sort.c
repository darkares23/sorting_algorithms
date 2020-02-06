#include "sort.h"
#include <stdlib.h>

/**
* counting_sort - sorts array integers in ascending order using Counting sort
* @size: size of the array
* @array: pointer to array
*
*/
void counting_sort(int *array, size_t size)
{
	int mayor = 0, j;
	size_t i;
	int *new_array, *tmp_array;

	if (array == NULL || size < 2)
		return;
	tmp_array = malloc((size) * sizeof(int));
	if (tmp_array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp_array[i] = array[i];
		if (array[i] > mayor)
			mayor = array[i];
	}
	new_array = malloc((mayor + 1) * sizeof(int));
	if (new_array == NULL)
		return;
	for (j = 0; j < (mayor + 1); j++)
		new_array[j] = 0;
	for (i = 0; i < size; i++)
		new_array[array[i]] += 1;
	for (j = 1; j < (mayor + 1); j++)
		new_array[j] += new_array[j - 1];
	print_array(new_array, (size_t)(mayor + 1));
	for (i = 0; i < size; i++)
	{
		array[new_array[tmp_array[i]] - 1] = tmp_array[i];
		new_array[tmp_array[i]] -= 1;
	}
	free(tmp_array);
	free(new_array);
}
