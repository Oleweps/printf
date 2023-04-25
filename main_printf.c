#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _printf - function to print different values in terminal
 * @format: string to format
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int y, count = 0, len = _strlen(format);
	char *symbol, *str;

	type_format symbols[] = {
		{"char", "%c"},
		{"string", "%s"},
		{"percent", "%%"},
		{"integer", "%d"},
		{"integer", "%i"},
		{"binary", "%b"},
		{NULL, NULL}
	};

	va_start(args, format);

	/** pointer to hold the symbol we find in the format string */
	symbol = malloc(sizeof(char) * 10);
	str = malloc(sizeof(char) * (len + 1));

	/** check for malloc failure */
	if (str == NULL)
	{
		return (0);
	}
	symbol[10] = '\0'; /** add null printer to the end */
	_strcpy(str, format);

	/**
	 * loop over the format string
	 */
	for (y = 0;  str[y] != '\0'; y++)
	{
		/** we reset the data in the memory location symbol is pointing to */
		_memset(symbol, 0, 10);
		if (str[y] == '%')
		{
			symbol[0] = str[y];
			symbol[1] = str[y + 1];
			y++;
		}
		if (symbol)
		{
			count += print_values_for_symbols(symbols, symbol, args);
		}
		/** function to print string characters */
		count += print_character(y, str);
	}

	va_end(args);
	free(symbol);

	return (count);
}
