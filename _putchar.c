#include <unistd.h>
#include <stdio.h>

#define START 1

/**
 * _putchar - function to print single character in terminal
*/

int _putchar(int ch)
{
    char c = (char)ch;

    return write(START, &c, 1);
}