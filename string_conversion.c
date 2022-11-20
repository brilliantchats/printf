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
		exit(1);
	while (str[i] != '\0')
	{
		num += print_char(str[i]);
		i++;
	}
	return (num);
}
