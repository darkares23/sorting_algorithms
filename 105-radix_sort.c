#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sort an array using radix sort
 *
 * @array: array unsorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int i, mayor = 0, count = 0, j, count_1 = 0, count_2 = 0, x = 1;
	int *tmp_array;

	if (array == NULL || size < 2)
		return;
	tmp_array = malloc((size) * sizeof(int));
	if (tmp_array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > mayor)
			mayor = array[i];
	}
	while (mayor >= 1)
	{
		mayor = mayor / 10;
		count += 1;
	}
	for (j = 0; j < count; j++)
	{
		while (count_2 < (int)size)
		{
			for (i = 0; i < (int)size; i++)
			{
				if ((array[i] / x) % 10 == count_1)
					{
						tmp_array[count_2] = array[i];
						count_2++;
					}
			}
			count_1++;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = tmp_array[i];
		print_array(array, size);
		count_1 = 0;
		count_2 = 0;
		x = x * 10;
	}
	free(tmp_array);
}
