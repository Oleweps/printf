#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct formats - structure to hold the,
 * different symbols and formats to check for.
 * @type: type to check of symbol
 * @symbol: the symbol value
 */

typedef struct formats
{
	char *type;
	char *symbol;
} type_format;

int _putchar(int ch);
int _strlen(const char *s);
int _printf(const char *format, ...);
int print_string(char *s);
int print_integer(long int num);
long int convert_negative_to_positive(long int n);
long int reverse_number(long int n);
char *_strcpy(char *dest, const char *src);
char *_memset(char *s, char b, unsigned int n);
int print_character(int idx, char *s);
int print_values_for_symbols(type_format *symbols, char *symbol, va_list args);
unsigned int convert_to_binary(unsigned int num);

#endif
