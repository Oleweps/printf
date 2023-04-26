#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _convert_to_octal - function to convert,
 * and print hexidecimal form of a number
 * @num: number to print binary form of
 * Return: number of character printed
 */

unsigned int _convert_to_octal(unsigned int num)
{
	int x, count = 0, rem;
	char *nums, *tmp;

	nums = malloc(sizeof(char *) * 1);
	if (nums == NULL)
	{
		return (0);
	}
	/** we first divide the value by the 2 and store the remainder char nums*/
	for (x = 0; num > 0; x++)
	{
		tmp = realloc(nums, sizeof(char) * (x + 1));
		if (tmp)
		{
			nums = tmp;
		}
		rem = num % 8;
		nums[x] = rem + '0';
		num = num / 8;
	}
	nums[x] = '\0';
	/** print number store in nums array */
	count = print_string_values(x, nums);

	return (count);
}

