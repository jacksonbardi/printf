#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, num;
	char ch;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
			count += _putchar(*format);
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				count += _putint(num);
			}
			else if (*format == 's')
				count += _puts(va_arg(args, char *));
			else if (*format == 'c')
			{
				ch = (char)va_arg(args, int);
				count += _putchar(ch);
			}
			else if (*format == '%')
				_putchar('%'), count++;
			else
				_putchar('%'), _putchar(*format), count += 2;
		}
		format++;
	}
	va_end(args);

	return (count);
}
