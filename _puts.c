#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _puts - prints a string to stdout
 * @str: The string to print
 *
 * Return: The length of the string
 */
int _puts(char *str)
{
	int i;

	if (str == NULL)
	{
		_puts("(null)");
		return (6);
	}

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
