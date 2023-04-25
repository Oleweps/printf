#include "main.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * print_integer - function to print an integer in the terminal
 * @num: number to be printed
 * Return: how many numbers were printed in the terminal
 */

int print_integer(long int num)
{
	long int x, len = 0, tmp = num;
	long int rev_n = 0;

	if (num >= INT_MIN || num <= INT_MAX)
	{
		rev_n = reverse_number(num);
		/** * print the number after reversing */
		x = 0;
		while (rev_n >= 1)
		{
			_putchar(((long int)rev_n % 10) + '0');
			rev_n /= 10;
			len += 1;
			x++;
		}
		/** add 0 if the number had zeroes at the end */
		if (tmp > 0)
		{
			while ((long int)tmp % 10 == 0)
			{
				_putchar(0 + '0');
				tmp /= 10;
				len += 1;
			}
		}
		return (len);
	}

	return (0);
}

/**
 * reverse_number - function to reverse a number
 * @n: number to be reversed
 * Return: pointer to reversed array
 */

long int reverse_number(long int n)
{
	int x;
	long int rev_n = 0;

	if (n < 0)
	{
		n = convert_negative_to_positive(n);
	}
	x = 0;
	while (n >= 1)
	{
		rev_n =  (rev_n * 10) + ((long int)n % 10);
		n = n / 10;
		x++;
	}

	return (rev_n);
}

/**
 * convert_negative_to_positive - function to convert,
 * negative number to positive
 * @n : number to be converted
 * Return: @n as a positive number
 */

long int convert_negative_to_positive(long int n)
{
	n *= -1;
	_putchar('-');

	return (n);
}
