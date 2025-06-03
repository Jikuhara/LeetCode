#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	maxSubArray(int *nums, int numsSize)
{
	int currentSum;
	int i;
	int maxSum;

	currentSum = nums[0];
	maxSum = nums[0];
	i = 1;
	while (i < numsSize)
	{
		if (currentSum < 0)
			currentSum = nums[i];
		else
			currentSum += nums[i];
		if (maxSum < currentSum)
			maxSum = currentSum;
		i++;
	}
	return (maxSum);
}