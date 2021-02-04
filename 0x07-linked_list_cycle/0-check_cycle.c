#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *check_cycle - Function that checks if a singly linked list has a cycle in it
 *@list: listint
 *Return: 0 if there is no cycle, 1 if there is a cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *tmp1 = list, *tmp2 = list;

	while (tmp1 && tmp2 && tmp2->next)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next->next;
		if (tmp1 == tmp2)
		{
			return (1);
		}
	}
	return (0);
}
