#include "main.h"

/** 
 * _strcpy - function to print out a string
 * @str: the string array
 * Return: pointer to new string
*/

char *_strcpy(char *dest, const char *src)
{
    int x;
    int len = _strlen(src);

    _memset(dest, 0 , _strlen(dest)); /** turn all values in string to zero*/

    for (x = 0; x <= len; x++)
    {
        dest[x] = src[x];
    }
    return (dest);
}