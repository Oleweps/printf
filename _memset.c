#include "main.h"

/**
 * *_memset - function to set values of a string to the specifed values of int
 * @s: string to reset memory
 * @b: character to reset string with
 * @n: index to end resting string at
 * Return: pointer to reset string
*/

char *_memset(char *s, char b, unsigned int n)
{
    unsigned int x;

    for (x = 0; x < n; x++)
    {
        s[x] = b;
    }

    return (s);
}