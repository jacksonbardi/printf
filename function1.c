#include "main.h"

/*<<<<<<<<<< PRINT UNSIGNED NUMBER >>>>>>>>>>*/
/* Function:print_unsigned
 * Description: Prints an unsigned long integer to the specified buffer.
 * Parameters:
 *   - types: A variable argument list.
 *   - buffer: The destination buffer for the printed unsigned integer.
 *   - flags: Flags for formatting.
 *   - width: Width for formatting.
 *   - precision: Precision for formatting.
 *   - size: Size for formatting.
 * Return: The number of characters written.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/* Function:print_octal
 * Dscrptn: Prnts the octal rprsnttn of an unsgnd lng intger to the spcfed bffer.
 * Parameters:
 *   - types: A variable argument list.
 *   - buffer: The destination buffer for the printed octal representation.
 *   - flags: Flags for formatting.
 *   - width: Width for formatting (not used in this function).
 *   - precision: Precision for formatting (not used in this function).
 *   - size: Size for formatting.
 * Return: The number of characters written.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*<<<<<<<<<< PRINT UNSIGNED NUMBER IN HEXADECIMAL >>>>>>>>>>*/
/* Function: print_hexadecimal
 * Dscrptn: Prnts the lowrcse hxdcmal reprsnttn of an unsgnd lng intgr to the spcifd buffr.
 * Parameters:
 *   - types: A variable argument list.
 *   - buffer: The destination buffer for the printed lowercase hexadecimal representation.
 *   - flags: Flags for formatting.
 *   - width: Width for formatting.
 *   - precision: Precision for formatting.
 *   - size: Size for formatting.
 * Return: The number of characters written.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*<<<<<<<<<< PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL >>>>>>>>>>*/
/* Function:print_hexa_upper
 * Dscrtn: Prnts the upprcse hexdcml reprsnttn of an unsgnd long intgr to the spcfd bffr.
 * Parameters:
 *   - types: A variable argument list.
 *   - buffer: The destntn buffer for the printed upprcase hexadcmal represntatn.
 *   - flags: Flags for formatting.
 *   - width: Width for formatting.
 *   - precision: Precision for formatting.
 *   - size: Size for formatting.
 * Return: The number of characters written.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*<<<<<<<<<< PRINT HEXX NUM IN LOWER OR UPPER >>>>>>>>>>*/
/* Function:print_hexa
 * Dscriptn: Prints the hexdecimal reprsnttin of an unsigned long integer to the spcfd bffer.
 * Parameters:
 *   - types: A variable argument list.
 *   - map_to: Array mapping hexadecimal digits.
 *   - buffer: The destination buffer for the printed hexadecimal reprsentatin.
 *   - flags: Flags for formatting.
 *   - flag_ch: The character for flag formatting.
 *   - width: Width for formatting (not used in this function).
 *   - precision: Precision for formatting (not used in this function).
 *   - size: Size for formatting.
 * Return: The number of characters written.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
