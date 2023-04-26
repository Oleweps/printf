#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

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

int _printf(const char *format, ...);
int _putchar(int ch);
int _strlen(const char *s);
int print_string(char *s);
int print_number(long int num);
long int convert_negative_to_positive(long int n);
long int reverse_number(long int n);
char *_strcpy(char *dest, const char *src);
char *_memset(char *s, char b, unsigned int n);
int print_character(int idx, char *s);
int print_values_for_symbols(type_format *symbols, char *symbol, va_list args);
unsigned int _convert_to_binary(unsigned int num);
unsigned int _convert_to_hexidecimal(unsigned int num, char *symbol);
unsigned int _convert_to_octal(unsigned int num);
unsigned int print_string_values(int len, char *nums);

#endif
