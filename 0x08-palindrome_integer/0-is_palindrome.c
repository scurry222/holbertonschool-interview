#include "palindrome.h"

/**
 * is_palindrome - Determine if number is a palindrome
 * @n: Unsigned long integer to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long int n)
{
	unsigned long int copy = n;
	unsigned long int rev = 0;
	unsigned long int rem = 0;

	while (n > 0)
	{
		rem = n % 10;
		n = (n - rem) / 10;
		rev = rev * 10 + rem;
	}

	return (rev == copy ? 1 : 0);
}
