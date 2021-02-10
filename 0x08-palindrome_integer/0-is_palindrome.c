#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
*is_palindrome-checks whether or not a given unsigned integer is a palindrome
*@n: is the number to be checked
*Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	static unsigned long reverse = 0, mod;

	if (n > 0)
	{
		mod = n % 10;
		reverse = reverse * 10 + mod;
		is_palindrome(n / 10);
	}
	if (reverse == n)
		return (1);
	else
		return (0);
}
