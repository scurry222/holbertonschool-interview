#include "lists.h"


/**
 * size_of - Find size of the linked list
 * @head: pointer to head of the linked list
 * 
 * Return: size of the LL
 */
int size_of(listint_t **head)
{
	int size = 0;
	listint_t *traverse = *head;

	while (traverse)
	{
		size++;
		traverse = traverse->next;
	}
	return (size);
}

/**
 * top - Find index of last element in the stack
 * @stack: array to traverse
 *
 * Return: last element
 */
int top(int *stack)
{
	int i;

	for (i = 0; stack[i]; i++)
	;

	return (i - 1);
}

/**
 * is_palindrome - Check if Singly Linked List is a palindrome
 * @head: Pointer to start of the LL
 * 
 * Return: 1 if LL is a palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	int  *stack, size, last, i = 0;
	listint_t *node;

	if (!head)
		return (1);

	size = size_of(head);
	stack = malloc((size / 2) - 1);

	node = *head;

	while (i < size / 2)
	{
		stack[i] = node->n;
		node = node->next;
		i++;
	}

	last = top(stack);

	while (node)
	{
		if (node->n != stack[last])
			return (0);
		node = node->next;
		last--;
	}
	return (1);
}
