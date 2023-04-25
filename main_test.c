#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	printf("Let's try to printf a simple sentence.\n");
	len = _printf("Character:[%c%%]\n", 'H');
	_printf("%d", len);
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Len:[%d]\n", INT_MAX);
	printf("Len:[%d]\n", INT_MAX);
	_printf("Len:[%d]\n", INT_MIN);
	printf("Len:[%d]\n", INT_MIN);
	_printf("%b\n", 8);
	return (0);
}
