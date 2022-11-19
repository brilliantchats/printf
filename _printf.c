#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * char_str_conversion - Handles printing of char, str and %
 * @character: Conversion specifier
 * @args: list of variable arguments
 *
 * Return: number of printed characters
 */
int char_str_conversion(char character, va_list args)
{
	int numb = 0;

	switch (character)
	{
		case 'c':
			numb += print_char(((char) va_arg(args, int)));
			break;
		case 's':
			numb += string_conversion(va_arg(args, char *));
			break;
		case '%':
			numb += print_char(character);
			break;
	}
	return (numb);
}
/**
 * _printf - Prints output according to format
 * @format: The format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, num_char = 0;
	va_list args;

	if (format == NULL)
	{
		return (0);
	}
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == 's'
			|| format[i + 1] == '%')
			{
				num_char += char_str_conversion(format[i + 1], args);
				i = i + 2;
			}
		}
		else
		{
			num_char += print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (num_char);
}
