#include <stdio.h>
#include <stdlib.h>

int	rob(int *nums, int numsSize)
{
	int	current_sum[2];
	int	take_house;
	int	not_take_house;

	if (numsSize == 0)
	{
		return (0);
	}
	if (numsSize == 1)
	{
		return (nums[0]);
	}
	current_sum[0] = nums[0];
	current_sum[1] = nums[1];
	for (int i = 2; i < numsSize; i++)
	{
		take_house = nums[i] + current_sum[0];
		not_take_house = nums[i - 1];
		if (current_sum[0] < current_sum[1])
			current_sum[0] = current_sum[1];
		if (take_house > not_take_house)
		{
			current_sum[1] = take_house;
		}
		else
		{
			current_sum[1] = not_take_house;
		}
	}
	if (current_sum[1] > current_sum[0])
	{
		return (current_sum[1]);
	}
	else
	{
		return (current_sum[0]);
	}
}

int	main(void)
{
	int	nums[] = {1, 2, 5, 0, 3, 100};
	int	numsSize;

	numsSize = 10;
	// printf("%i\n", rob(nums, numsSize));
	for (int i = 1; i < numsSize; i++)
		printf("%i\n", rob(nums, i));
	return (0);
}
