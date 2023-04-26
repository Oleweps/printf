#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 *_convert_to_hexidecimal - function to convert and print hexidecimal form,
 * of a number
 * @num: number to print binary form of
 * @symbol: symbol to check check for
 * Return: number of character printed
 */

unsigned int _convert_to_hexidecimal(unsigned int num, char *symbol)
{
	unsigned int x, count = 0, rem;
	char *nums, *tmp;

	nums = malloc(sizeof(char *) * 1);
	if (nums == NULL)
	{
		return (0);
	}
	/** we first divide the value by the 2 and store the remainder nums */
	for (x = 0; num > 0; x++)
	{
		tmp = realloc(nums, sizeof(char) * (x + 1));
		if (tmp)
		{
			nums = tmp;
		}
		rem = (num % 16);
		if (rem < 10)
		{
			nums[x] = 48 + rem;
		}
		else
		{
			if (strcmp(symbol, "%x") == 0)
			{
				nums[x] = 87 + rem;
			}
			else
			{
				nums[x] = 55 + rem;
			}
		}
		num = num / 16;
	}
	nums[x] = '\0';
	count += print_string_values(x, nums); /** print hex value */
	free(nums);

	return (count);
}

