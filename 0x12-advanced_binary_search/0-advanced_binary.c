#include "search_algos.h"
#include <stdio.h>
/**
*advanced_binary - Function that searches for a value in an array of integers
*@array: Pointer to the first element o the array to search in
*@size: The number of elements in array
*@value: The value to search for
*Return: Value if it is present, if value isn ot present return -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t min, max, i;
	int mid;

	min = 0;
	max = size - 1;

	if (array == NULL)
		return (-1);
	while (min <= max)
	{
		mid = (min + max) / 2;
		printf("Searching in array: ");

		for (i = min; i < max; i++)
			printf("%d, ", array[i]);

		if (i == max)
			printf("%d\n", array[i]);

		if (array[mid] < value)
			min = mid + 1;

		else if (array[mid] > value)
			max = mid - 1;

		else
			return (mid);
	}
	return (-1);
}
