#include "lists.h"
/**
*
*
*
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
*
*
*
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
