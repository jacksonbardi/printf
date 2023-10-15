#include "main.h"
#include <limits.h>

/**
 * _putint - prints an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of digits printed
 */
int _putint(int n)
{
	int count = 0;

	if (n == 0)
		return (_putchar('0'), 1);
	if (n == INT_MIN)
	{
		/* Handle the special case of INT_MIN */
		count += _puts("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += _putint(n / 10);

	return (count + _putchar('0' + (n % 10)));
}
