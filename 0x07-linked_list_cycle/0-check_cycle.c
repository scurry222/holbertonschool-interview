#include "lists.h"

/**
* find_listint_loop - finds loops within linked lists
* @head: pointer to first element
*
* Return: pointer to start of the loop
*/

int check_cycle(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head)
		return (0);

	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (1);
		}
	}
	return (0);
}
