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
	char check_letters[] = "csdbilfguoexX%";
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
