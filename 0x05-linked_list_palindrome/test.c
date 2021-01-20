#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * is_palindrome- Function that verify if linked list is palindrome
 * @head: Double pointer
 * Return: Integer 1 or 0, if it is palindrome or not.
*/
int is_palindrome(listint_t **head)
{
	listint_t *temp, *temp2 = *head;

	int lenght = 0, num = 0;

	if (*head == NULL)
		return (1);

	pali_recurisive(&temp, temp2, &lenght, &num);
	if (lenght == num)
		return (1);
	else
		return (0);
}

/**
*pali_recurisive- Check palindrome
*@head: pointer
*@temp: pointer
*@l: integer
*@n: integer
*Return: Integer
*/

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
