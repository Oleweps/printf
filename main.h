#include <stdarg.h>
#ifndef MAIN_H__
#define MAIN_H__

int _putchar(char ch);
int _strlen(char *s);
int _printf(const char *format, ...);
void print_string(char *);
void print_int(int num);
void print_float(float num);

/**
 * formats - structure to hold the different symbols and formats to check for.
 * @type: type to check of symbol
 * @symbol: the symbol value
 * @f: function pointer to hold functions that work on different symbols
*/
typedef struct formats
{
    char *type;
    char *symbol;
    void (*f)(const int len, ...);
} type_format;

#endif