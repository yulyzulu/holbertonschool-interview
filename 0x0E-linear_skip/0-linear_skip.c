#include "search.h"

/**
*linear_skip - Searches for a value in a sorted skip list of integers
*@list: Pointer to the head of the skip list to search in
*@value: Value to search for
*Return: Pointer on the first node where value is located
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip_list;
	size_t idx1, idx2;

	if (list == NULL)
		return (NULL);

	while (list->next && list->n < value)
	{
		if (list->express)
		{
			skip_list = list;
			list = list->express;
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (!list->express && value > list->n)
				skip_list = list;
		}
		else
			list = list->next;
	}
	idx1 = skip_list->index, idx2 = list->index;
	printf("Value found between indexes [%lu] and [%lu]\n", idx1, idx2);
	while (skip_list->next && skip_list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			skip_list->index, skip_list->n);
		skip_list = skip_list->next;
		if (!skip_list->next)
			printf("Value checked at index [%lu] = [%d]\n",
				skip_list->index, skip_list->n);
	}
	if (skip_list->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			skip_list->index, skip_list->n);
		return (skip_list);
	}
	return (NULL);

}
