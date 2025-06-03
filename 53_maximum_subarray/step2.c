#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	maxSubArray(int *nums, int numsSize)
{
	int *dp;
	int i;
	int max_sum;

	dp = malloc(sizeof(int) * numsSize);
	if (!dp)
		return (0);
	dp[0] = nums[0];
	max_sum = dp[0];
	i = 1;
	while (i < numsSize)
	{
		dp[i] = nums[i];
		if (dp[i] < dp[i - 1] + nums[i])
			dp[i] = dp[i - 1] + nums[i];
		if (max_sum < dp[i])
			max_sum = dp[i];
		i++;
	}
	free(dp);
	return (max_sum);
}