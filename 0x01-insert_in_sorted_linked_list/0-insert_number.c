#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Add node to start of list
 * @head: Pointer to curent head of list
 * @n: Integer to be copied into node
 *
 * Return: Pointer to new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * insert_node - Add number into sorted linked list
 * @head: Pointer to the current head of the list
 * @number: Integer to be copied into new node
 *
 * Return: Pointer to new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *current = NULL;

	if (!head)
		return (NULL);
	if (!*head)
	{
		new = add_nodeint(head, number);
		return (new);
	}
	if (!(*head)->next)
	{
		if ((*head)->n > number)
		{
			new = add_nodeint(head, number);
			return (new);
		}
		add_nodeint_end(head, number);
	}
	current = *head;
	if ((*head)->n > number)
	{
		new = add_nodeint(head, number);
		return (new);
	}
	while (current->next)
	{
		if (current->next->n > number)
			break;
		current = current->next;
	}
	new = malloc(sizeof(listint_t *));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = current->next;
	current->next = new;
	return (new);
}
