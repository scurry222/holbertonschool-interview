#include "lists.h"

/**
 * reverse - reverse the contents of the rest of the linked list after pointer.
 * @head: Pointer to start of the LL
 */
void reverse(listint_t **head)
{
	listint_t *node = *head, *next, *prev = NULL;

	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	*head = prev;
}

/**
 * is_palindrome - Check if Singly Linked List is a palindrome
 * @head: Pointer to start of the LL
 *
 * Return: 1 if LL is a palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *node = *head, *fast = *head, *slow = *head, *rev = NULL;

	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	reverse(&slow);

	while (node && rev)
	{
		if (node->n != rev->n)
			return (0);
		node = node->next;
		rev = rev->next;
	}
	return (1);
}
