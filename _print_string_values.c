#include "main.h"

/**
 * print_string_values - function to print hex value in array
 * @len: length of array
 * @nums: array string hex values
 * Return: number of elements printed in terminal
 */

unsigned int print_string_values(int len, char *nums)
{
	int x = len - 1, count = 0;

	/** print number store in nums array */
	for (x = x; nums[x] != 0; x--)
	{
		_putchar(nums[x]);
		count++;
	}

	return (count);
}
