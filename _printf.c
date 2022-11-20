#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * format_convertor - Chooses which function to call for a specifier
 * @specifier: Conversion specifier
 * @args: list of variable argumets
 *
 * Return: number of characters printed
 */
int format_convertor(char specifier, va_list args)
{
	int number_of_char = 0;

	if (specifier == 'c' || specifier == 's' || specifier == '%')
		number_of_char += char_str_conversion(specifier, args);
	if (specifier == 'b')
		number_of_char += unsigned_to_binary(va_arg(args, unsigned int));
	if (specifier == 'u')
		number_of_char += unsigned_convertor(va_arg(args, unsigned int));
	return (number_of_char);
}
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
			num_char += format_convertor(format[i + 1], args);
			i = i + 2;
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
