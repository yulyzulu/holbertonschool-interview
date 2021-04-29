#include "search_algos.h"
#include <stdio.h>
/**
*search - Function that searches for a value in an array of integers
*@array: Pointer to the first element o the array to search in
*@min: minimum value of the array
*@max: maximum value of the array
*@value: The value to search for
*Return: Value if it is present, if value is not present return -1
*/
int search(int *array, int min, int max, int value)
{
	int mid, i;

	mid = (min + max) / 2;

	if (min > max)
		return (-1);
	printf("Searching in array: ");
	for (i = min; i <= max; i++)
	{
		if (i == max)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (array[mid] == value)
	{
		if (array[mid - 1] == value)
			return (search(array, min, mid, value));
		return (mid);
	}
	else if (array[mid] >= value)
		return (search(array, min, mid, value));
	else
		return (search(array, mid + 1, max, value));
	return (-1);
}

/**
*advanced_binary - Function that searches for a value in an array of integers
*@array: Pointer to the first element o the array to search in
*@size: The number of elements in array
*@value: The value to search for
*Return: the index of the value searched
*/
int advanced_binary(int *array, size_t size, int value)
{
	int min, max;

	min = 0;
	max = (int)size - 1;

	if (array == NULL || size <= 0)
		return (-1);
	return (search(array, min, max, value));
}
