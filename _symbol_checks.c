#include "main.h"
#include <string.h>

/**
 * check_alphabets - function to check symbols,
 * that format characters and strings
 * @symbol_type: pointer to symbol type to check for
 * @args: values in va_list
 * Return: number of integers printed in terminal
 */

int check_alphabets(char *symbol_type, va_list args)
{
	int count = 0;

	if (strcmp(symbol_type, "char") == 0)
	{
		_putchar(va_arg(args, int));
		count += 1;
	}
	if (strcmp(symbol_type, "string") == 0)
	{
		count += print_string(va_arg(args, char *));
	}

	return (count);
}

/**
 * check_percent - function to check symbols that format percent symbol
 * @symbol_type: pointer to symbol type to check for
 * Return: number of integers printed in terminal
 */

int check_percent(char *symbol_type)
{
	if (strcmp(symbol_type, "percent") == 0)
	{
		_putchar('%');
	}

	return (1);
}

/**
 * check_numbers - function to check symbols that format numbers
 * @symbol_type: pointer to symbol type to check for
 * @args: values in va_list
 * Return: number of integers printed in terminal
 */

int check_numbers(char *symbol_type, va_list args)
{
	int count = 0;

	if (strcmp(symbol_type, "integer") == 0)
	{
		count += print_number(va_arg(args, int));
	}
	if (strcmp(symbol_type, "unsigned_int") == 0)
	{
		count += print_number(va_arg(args, unsigned int));
	}

	return (count);
}

/**
 * check_other_symbols - function to check symbols for other formats
 * @symbol_type: pointer to symbol type to check for
 * @symbol: pointer to symbol to check for
 * @args: values in va_list
 * Return: number of integers printed in terminal
 */

int check_other_symbols(char *symbol_type, char *symbol, va_list args)
{
	int count = 0;

	if (strcmp(symbol_type, "binary") == 0)
	{
		count += _convert_to_binary(va_arg(args, unsigned int));
	}
	if (strcmp(symbol_type, "octal") == 0)
	{
		count += _convert_to_octal(va_arg(args, unsigned int));
	}
	if (strcmp(symbol_type, "hexidecimal") == 0)
	{
		count += _convert_to_hexidecimal(va_arg(args, unsigned int), symbol);
	}

	return (count);
}

/**
 * print_values_for_symbols - function to check ,
 * for the different types of symbols
 * @symbols: pointer to type_format array
 * @symbol: pointer to symbol to check for
 * @args: values in va_list
 * Return: number of character printed
 */

int print_values_for_symbols(type_format *symbols, char *symbol, va_list args)
{
	int j, count = 0;

	for (j = 0; symbols[j].type != NULL; j++)
	{
		if (strcmp(symbol, symbols[j].symbol) == 0)
		{
			if (strcmp(symbols[j].type, "char") == 0)
			{
				_putchar(va_arg(args, int));
				count += 1;
			}
			if (strcmp(symbols[j].type, "string") == 0)
			{
				count += print_string(va_arg(args, char *));
			}
			if (strcmp(symbols[j].type, "percent") == 0)
			{
				_putchar('%');
				count += 1;
			}
			if (strcmp(symbols[j].type, "integer") == 0)
			{
				count += print_number(va_arg(args, int));
			}
			if (strcmp(symbols[j].type, "binary") == 0)
			{
				count += _convert_to_binary(va_arg(args, unsigned int));
			}
			count += check_other_symbols(char *symbol_type, char *symbol, va_list args);
			break;
		}
	}

	return (count);
}

