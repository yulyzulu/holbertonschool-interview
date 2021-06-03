#include "lists.h"
/**
*loop - Find the loop
*@tmp1: Pointer
*@tmp2: Pointer
*Return: Pointer where the loop start
*/
listint_t *loop(listint_t *tmp1, listint_t *tmp2)
{
	while (tmp1 != tmp2)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return (tmp1);
}

/**
*find_listint_loop - Function that finds the loop in a linked list
*@head: Pointer to the linked list head
*Return: The address of the node where the loop starts, or NULL
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp1, *tmp2;

	if (head)
	{
		tmp1 = head->next;
		tmp2 = head->next->next;
		while (tmp1 && tmp2)
		{
			if (tmp1 == tmp2)
			{
				tmp1 = head;
				return (loop(tmp1, tmp2));
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next->next;
		}
	}
	return (NULL);
}
