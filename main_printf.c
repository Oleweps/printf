#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/** 
 * _printf - function to print different values in terminal
 * @format: string to format
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
    /** keeping track of all the symbols */
    type_format symbols[] = 
    {
        {"char", "%c", _putchar},
        {"string", "%s", print_string},
        {"int", "%d", print_int},
        {"float", "%f", print_float},
        {"percent", "%%", _putchar},
        {NULL, NULL, NULL}
    };

    return (0);
}