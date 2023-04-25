#include "main.h"

/**
 * _strlen - function to get the length of a string
 * @s: pointer to string to get length of
 * Return: length of the string
*/

int _strlen(const char *s)
{
    unsigned int x, len = 0;

    if (s)
    {
        for (x = 0; s[x] != '\0';  x++)
        {
            len += 1;
        }
    }

    return (len);
}