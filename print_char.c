#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_char - Prints a char to standard output
 * @c: the character to be printed
 *
 * Return: 1 on success, -1 on failure
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
