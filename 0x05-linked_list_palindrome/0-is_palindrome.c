#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_palindro - traverse linked list
 * @head: doble pointer head linked list
 * @temp: pointer
 * @lenght: integer lenght
 * @num: integer
 * Return: number of nodes
 */
void check_palindro(listint_t **head, listint_t *temp, int *lenght, int *num)
{
	if (temp != NULL)
	{
		*lenght = *lenght + 1;
		check_palindro(head, temp->next, lenght, num);
		if ((*head)->n == temp->n)
		{
			*head = (*head)->next;
			*num = *num + 1;
			return;
		}
		return;
	}
}

/**
 * is_palindrome - check if a linked list is palindrome or not
 * @head: double pointer to head of linked list
 * Return: 1 it is palindrome or 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp1 = *head;
	listint_t *temp2 = *head;
	int lenght = 0, num = 0;

	check_palindro(&temp1, temp2, &lenght, &num);

	if (lenght == num)
		return (1);
	else
		return (0);

}
