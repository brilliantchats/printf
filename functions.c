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
	free(binary_str);
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
	free(unsigned_str);
	return (length);
}
/**
 * octal_convertor - Handles o conversion to Octal printing on std output
 * @num: the unsigned number to be converted to octal
 *
 * Return: the number of characters printed
 */
int octal_convertor(unsigned int num)
{
	int length = 0, i;
	unsigned int num_cpy = num;
	char *octal_str;

	if (num < 8)
	{
		print_char(num + '0');
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 8;
		length++;
	}
	octal_str = malloc(sizeof(char) * length);
	if (octal_str == NULL)
		return (0);
	for (i = length - 1; i >= 0; i--)
	{
		octal_str[i] = ((num % 8) + '0');
		num = num / 8;
	}
	for (i = 0; i < length; i++)
		print_char(octal_str[i]);
	free(octal_str);
	return (length);
}
/**
 * hexa_convertor - Converts unsigned int to hex, mimics %x
 * @num: the unsigned int to be converted
 *
 * Return: the number of characters printed
 */
int hexa_convertor(unsigned int num)
{
	int length = 0, i;
	unsigned int num_cpy = num;
	char *hexa_str;
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	if (num < 16)
	{
		if (num < 10)
			print_char(num + '0');
		else
			print_char(arr[(num % 10)]);
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 16;
		length++;
	}
	hexa_str = malloc(sizeof(char) * length);
	if (hexa_str == NULL)
		return (0);
	for (i = length - 1; i >= 0; i--)
	{
		if ((num % 16) < 10)
			hexa_str[i] = (num % 16) + '0';
		else
			hexa_str[i] = arr[((num % 16) - 10)];
		num = num / 16;
	}
	for (i = 0; i < length; i++)
		print_char(hexa_str[i]);
	free(hexa_str);
	return (length);
}
/**
 * heXa_convertor - Converts unsigned int to hexadecimal number via %X
 * @num: the unsigned int
 *
 * Return: number of characters printed
 */
int heXa_convertor(unsigned int num)
{
	int length = 0, i;
	unsigned int num_cpy = num;
	char *heXa_str;
	char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if (num < 16)
	{
		if (num < 10)
			print_char(num + '0');
		else
			print_char(arr[(num % 10)]);
		return (1);
	}
	while (num_cpy != 0)
	{
		num_cpy = num_cpy / 16;
		length++;
	}
	heXa_str = malloc(sizeof(char) * length);
	if (heXa_str == NULL)
		return (0);
	for (i = length - 1; i >= 0; i--)
	{
		if ((num % 16) < 10)
			heXa_str[i] = ((num % 16) + '0');
		else
			heXa_str[i] = arr[((num % 16) - 10)];
		num = num / 16;
	}
	for (i = 0; i < length; i++)
		print_char(heXa_str[i]);
	free(heXa_str);
	return (length);
}
