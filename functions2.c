#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * string_conversion - Prints a string to standard output
 * @str: The string passed from the _printf function
 *
 * Return: number of characters printed, 0 if string is NULL
 */
int string_conversion(char *str)
{
	int i = 0, num = 0; /* num is numbr of char */

	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		num += print_char(str[i]);
		i++;
	}
	return (num);
}
/**
 * decimal_int_convertor - Handle %d and %i
 * @num: the number
 *
 * Return: number of characters printed
 */
int decimal_int_convertor(int num)
{
	int length = 0, num_cpy = num, sign = 0, i;
	char *num_str;

	if (num < 0)
	{
		num = num * -1;
		num_cpy = num_cpy * -1;
		sign++;
	}
	if (num == 0)
	{
		print_char(num + '0');
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 10;
		length++;
	}
	num_str = malloc(sizeof(char) * (length + sign));
	if (num_str == NULL)
		return (0);
	for (i = length + sign - 1; i >= 0; i--)
	{
		if (sign == 1 && i == 0)
			num_str[i] = '-';
		else
			num_str[i] = ((num % 10) + '0');
		num = num / 10;
	}
	for (i = 0; i < (length + sign); i++)
		print_char(num_str[i]);
	free(num_str);
	return (length + sign);
}
