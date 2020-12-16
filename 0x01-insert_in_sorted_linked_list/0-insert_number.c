#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
*insert_node - Insert new node in a sorted single linked list
*@head: pointer of first node of listint_t list
*@number: integer to include in new node
*Return: new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *aux1;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	aux1 = *head;
	new_node->n = number;

	if (*head == NULL || (*head)->n >= new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (aux1->next != NULL && aux1->next->n < new_node->n)
	{
		aux1 = aux1->next;
	}
	new_node->next = aux1->next;
	aux1->next = new_node;

	return (new_node);
}
