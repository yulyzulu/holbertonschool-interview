#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
*swap - swap function
*@a: swap value
*@b: swap value
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
*siftDown - Function that treats the entire input array as a full but
*"broken" heap and "repairs" it starting from the last non-trivial sub-heap
*@array: array to sort
*@start: start array
*@end: end array
*@size: size of array
*/
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child = child + 1;
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
*heapify - Function to build a heap
*@array: array to sort
*@size: size of array
*/
void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start = start - 1;
	}
}

/**
*heap_sort - Function that sorts an array of integers in ascending order
*@array: Array to sort
*@size: Size array
*/
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (size < 2)
		return;

	heapify(array, size);
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end = end - 1;
		siftDown(array, 0, end, size);
	}
}
