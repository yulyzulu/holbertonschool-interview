#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void pali_recurisive(listint_t **head, listint_t *temp, int *l, int *n)
{
	if (temp != NULL)
	{
		*l = *l + 1;
		pali_recurisive(head, temp->next, l, n);
		if ((*head)->n == temp->n)
		{
			*head = (*head)->next;
			*n = *n + 1;
			return;
		}
		return;
    	}
}

int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *temp2 = *head;
	int lenght = 0, num = 0;
	int s;

	if (*head == NULL)
		return (1);
	s = pali_recurisive(&temp, temp2, &lenght, &num);
	if (lenght == num)
		return (1);
	else
		return (0);
}
