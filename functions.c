#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * unsigned_to_binary - Takes an unsigned integer, converts to binary
 * @num: the unsigned integer
 *
 * Return: number of characters printed
 */
int unsigned_to_binary(unsigned int num)
{
	int len_of_binary = 0, i;
	unsigned int num_cpy = num; /* make a copy of num to work on */
	char *binary_str;

	if (num == 0 || num == 1)
	{
		print_char(num + '0');
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 2;
		len_of_binary++;
	}
	binary_str = malloc(sizeof(char) * len_of_binary);
	if (binary_str == NULL)
		return (0);
	for (i = len_of_binary - 1; i >= 0; i--)
	{
		binary_str[i] = num % 2;
		num = num / 2;
	}
	for (i = 0; i < len_of_binary; i++)
		print_char(binary_str[i] + '0');
	return (len_of_binary);
}
/**
 * unsigned_convertor - Handles u conversion for unsigned numbers
 * @num: the unsigned number
 *
 * Return: the number of characters printed to standard output
 */
int unsigned_convertor(unsigned int num)
{
	int length = 0, i;
	unsigned int num_cpy = num;
	char *unsigned_str;

	if (num < 10)
	{
		print_char(num + '0');
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 10;
		length++;
	}
	unsigned_str = malloc(sizeof(char) * length);
	if (unsigned_str == NULL)
		return (0);
	for (i = length - 1; i >= 0; i--)
	{
		unsigned_str[i] = ((num % 10) + '0');
		num = num / 10;
	}
	for (i = 0; i < length; i++)
		print_char(unsigned_str[i]);
	return (length);
}
