#include "sort.h"

void h_helper(int *array, size_t size, int lo, int hi);
int h_partition(int *array, size_t size, int lo, int hi);
/**
 * quick_sort_hoare - quick sort array
 * @array: array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	h_helper(array, size, 0, size - 1);
}
/**
 * h_helper - helper of quick_sort function
 * @array: new array to sort
 * @size: size of new array
 * @lo: lower
 * @hi: higher
 */
void h_helper(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = h_partition(array, size, lo, hi);
		if (p > lo)
			h_helper(array, size, lo, p);
		h_helper(array, size, p + 1, hi);
	}
}
/**
 * h_partition - place pivot and partition the array
 * @array: array
 * @size: size
 * @lo: lower
 * @hi: higher
 *
 * Return: pivot index
 */
int h_partition(int *array, size_t size, int lo, int hi)
{
	int tmp, pivot = array[hi];
	/*int l = lo - 1, r = hi + 1;*/
	int l = lo, r = hi;

	while (1)
	{
		while (array[l] < pivot)
			l++;
		while (array[r] > pivot)
			r--;

		if (l < r)
		{
			tmp = array[l];
			array[l] = array[r];
			array[r] = tmp;
			print_array(array, size);
			l++;
			r--;
		}
		else
		{
			if (l != r)
				return (r);
			return (r - 1);
		}
	}
}
