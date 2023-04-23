#include "main.h"

/**
 * _strlen - function to get the length of a string
 * @s: pointer to string to get length of
 * Return: length of the string
*/

int _strlen(char *s)
{
    unsigned int x, len;

    for (x = 0; s[x] != '\0';  x++)
    {
        len += 1;
    }

    return (len);
}