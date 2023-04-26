#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_symbols - function that intializes ,
 * an array of type_format
 * @symbols: array of type_format to initialize
 * Return: pointer to array of type_format
 */
type_format *get_symbols(type_format symbols[])
{
	type_format *tmp;

	symbols[0].type = "char";
	symbols[0].symbol = "%c";
	symbols[1].type = "string";
	symbols[1].symbol = "%s";
	symbols[2].type = "percent";
	symbols[2].symbol = "%%";
	symbols[3].type = "integer";
	symbols[3].symbol = "%d";
	symbols[4].type = "integer";
	symbols[4].symbol = "%i";
	symbols[5].type = "binary";
	symbols[5].symbol = "%b";
	symbols[6].type = NULL;
	symbols[6].symbol = NULL;

	tmp = symbols;
	return (tmp);
}

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
	type_format *symbols, tmp[7];

	symbols = get_symbols(tmp);
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
	/** loop over the format string */
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
