#include "main.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

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
	char check_letters[] = "csdbilfguoe%";
	bool found = false;
	int x, count = 0;

	for (x = 0; check_letters[x] != '\0'; x++)
	{
		if (check_letters[x] == s[idx])
		{
			found = true;
			break;
		}
	}

	if (idx > 0)
	{
		/** check so that we don't print any of the symbols */
		if (!(s[idx - 1] == '%' && found))
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
	int x, count = 0;
	char *nums, *tmp;

	nums = malloc(sizeof(char *) * 1);
	if (nums == NULL)
	{
		return (0);
	}
	/** we first divide the value by the 2 and store the remainder int a[]*/
	for (x = 0; num > 0; x++)
	{
		/** reallocate x + 1 bytes to array */
		tmp = realloc(nums, sizeof(char) * (x + 1));
		if (tmp)
		{
			nums = tmp;
		}
		nums[x] = ((num % 2) + '0');
		num = num / 2;
	}
	nums[x] = '\0';
	/** print number stored in nums string array */
	for (x = (x - 1); nums[x - 1] != '\0'; x--)
	{
		_putchar(nums[x]);
		count++;
	}
	free(nums);
	return (count);
}
