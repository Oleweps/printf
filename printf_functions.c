#include "main.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
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
 * print_integer - function to print an integer in the terminal
 * @num: number to be printed
 * Return: how many numbers were printed in the terminal
*/

int print_integer(long int num)
{
    double x, len = 0, tmp = num;
    double rev_n = 0;

    if (num >= INT_MIN || num <= INT_MAX)
    {
        rev_n = reverse_number(num);
        /** 
         * print the number after reversing
        */
        x = 0;
        while(rev_n >= 1)
        {
            _putchar(((long int)rev_n % 10) + '0');
            rev_n /= 10;
            len += 1;
            x++;
        }
        /**
         * add 0 if the number had zeroes at the end
        */
        if (tmp > 0)
        {
            while((long int)tmp % 10 == 0)
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
 * @int_arr: array to add values
 * Return: pointer to reversed array 
*/

double reverse_number(double n)
{
    int x;
    double rev_n = 0;

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
 * convert_negative_to_positive - function to convert negative number to positive
 * @n : number to be converted
 * Return: @n as a positive number
*/
double convert_negative_to_positive(double n)
{
    if (n == INT_MIN)
    {
        n = (n * -1) - 1;
    }
    else
    {
        n *= -1;
    }
    _putchar('-');
    return (n);
}

/**
 * print_character - function to print character from string
 * @idx: index to use for the @s string
 * @s: string to print characters from 
 * @count: number of characters printed
 * Return: number of character printed
*/

int print_character(int idx, char *s)
{
    bool check_chars;
    int count = 0;

    if (idx > 0)
    {
        check_chars = (s[idx] == 'c' || s[idx] == 's' || s[idx] == '%' || s[idx] == 'd' || s[idx] == 'i');
        /** check so that we don't print any of the symbols */
        if (!(s[idx - 1] == '%' && (check_chars || s[idx] == 'b')))
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

    return count;
}

/**
 * print_values_for_symbols - function to check for the different types of symbols
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
            if(strcmp(symbols[j].type, "string") == 0)
            {
                /** calls print_string function */
                count += print_string(va_arg(args, char *));
            }
            if(strcmp(symbols[j].type, "percent") == 0)
            {
                _putchar('%');
                count += 1;
            }
            if(strcmp(symbols[j].type, "integer") == 0)
            {
                count += print_integer(va_arg(args, int));
            }
            if(strcmp(symbols[j].type, "binary") == 0)
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
        a[x] = num % 2;
        num = num / 2;
    }

    for (x = (x - 1); ; x--)
    {
        _putchar(a[x] + '0');
        count++;
    }

    return (count);
}