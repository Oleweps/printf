#include "main.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/**
 * print_string - function to print a string in terminal
 * @s: string to be printed
 * Return: number of characters printed
 */

int print_string(char *s)
{
	int k, len = 0;

	if (s)
	{
		for (k = 0; s[k] != '\0'; k++)
		{
			_putchar(s[k]);
			len += 1;
		}
	}

	return (len);
}

/**
 * print_character - function to print character from string
 * @idx: index to use for the @s string
 * @s: string to print characters from
 * Return: number of character printed
 */

int print_character(int idx, char *s)
{
	bool check_chars_1, check_chars_2;
	int count = 0;

	check_chars_1 = (s[idx] == 'c' || s[idx] == 's' || s[idx] == '%');
	check_chars_2 = (s[idx] == 'd' || s[idx] == 'b' || s[idx] == 'i');
	if (idx > 0)
	{
		if (s[idx - 1] == '%' && (!check_chars_1 && !check_chars_2))
		{
			_putchar('%');
			count = 1;
		}
		/** check so that we don't print any of the symbols */
		if (!(s[idx - 1] == '%' && (check_chars_1 || check_chars_2)))
		{
			_putchar(s[idx]);
			count = 1;
		}
	}
	else
	{
		_putchar(s[idx]);
		count = 1;
	}

	return (count);
}

/**
 * print_values_for_symbols - function to check ,
 * for the different types of symbols
 * @symbols: pointer to type_formar array
 * @symbol: pointer to symbol to check for
 * @args: va_list
 * Return: number of character printed
*/

int print_values_for_symbols(type_format *symbols, char *symbol, va_list args)
{
	int j, count = 0;

	/** loop over all the symbols */
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
				/** calls print_string function */
				count += print_string(va_arg(args, char *));
			}
			if (strcmp(symbols[j].type, "percent") == 0)
			{
				_putchar('%');
				count += 1;
			}
			if (strcmp(symbols[j].type, "integer") == 0)
			{
				count += print_integer(va_arg(args, int));
			}
			if (strcmp(symbols[j].type, "binary") == 0)
			{
				count += convert_to_binary(va_arg(args, unsigned int));
			}
			break;
		}
	}
	return (count);
}

/**
 * convert_to_binary - function to convert and print binary form of a number
 * @num: number to print binary form of
 * Return: number of character printed
 */

unsigned int convert_to_binary(unsigned int num)
{
	unsigned int a[10], x, count = 0;

	/** we first divide the value by the 2 and store the remainder int a[]*/
	for (x = 0; num > 0; x++)
	{
		a[x] = (num % 2);
		num = num / 2;
	}

	for (x = (x - 1); ; x--)
	{
		if (x == 0)
		{
			_putchar(a[0] + '0');
			break;
		}
		_putchar(a[x] + '0');
		count++;
	}
	return (count);
}
