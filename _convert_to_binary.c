#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _convert_to_binary - function to convert and print binary form of a number
 * @num: number to print binary form of
 * Return: number of character printed
 */

unsigned int _convert_to_binary(unsigned int num)
{
	int x, count = 0;
	char *nums, *tmp;

	nums = malloc(sizeof(char *) * 1);
	if (nums == NULL)
	{
		return (0);
	}
	/** we first divide the value by the 2 and store the remainder char nums*/
	for (x = 0; num > 0; x++)
	{
		/** reallocate x + 1 bytes to array */
		tmp = realloc(nums, sizeof(char) * (x + 1));
		if (tmp)
		{
			nums = tmp;
		}
		nums[x] = ((num % 2) + '0');
		num = num / 2;
	}
	nums[x] = '\0';

	/** print number store in nums array */
	for (x = (x - 1); nums[x - 1] != '\0'; x--)
	{
		_putchar(nums[x]);
	}
	free(nums);

	return (count);
}

