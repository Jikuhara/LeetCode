#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	maxSubArray(int *nums, int numsSize)
{
	int	*dp;
	int	i;
	int	max_sum;

	dp = malloc(sizeof(int) * numsSize);
	if (!dp)
		return (0);
	memcpy(dp, nums, sizeof(int) * numsSize);
	i = 1;
	while (i < numsSize)
	{
		if (dp[i] < dp[i - 1] + nums[i])
			dp[i] = dp[i - 1] + nums[i];
		i++;
	}
	max_sum = dp[0];
	i = 0;
	while (i < numsSize)
	{
		if (max_sum < dp[i])
			max_sum = dp[i];
		i++;
	}
	free(dp);
	return (max_sum);
}

int	main(void)
{
	int nums[] = {1, 2, -3, 4};
	int numsSize = 4;

	printf("%i\n", maxSubArray(nums, numsSize));
	return (0);
}