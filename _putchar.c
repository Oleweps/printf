#include <unistd.h>
#include <stdio.h>

#define START 1

/**
 * _putchar - function to print single character in terminal
 * @ch: character to be printed
 * Return: the return value of wite function
*/

int _putchar(int ch)
{
	if (ch > 0)
	{
		char c = (char)ch;

		return (write(START, &c, 1));
	}
	return (0);
}
