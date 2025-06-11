/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:47:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/02 14:19:49 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	findDuplicate(int *nums, int numsSize)
{
	int	left;
	int mid;
	int right;
	int	i;
	int	count;

	left = 0;
	right = numsSize - 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		count = 0;
		i = 0;
		while (i < numsSize)
		{
			if (nums[i] <= mid)
				count++;
			i++;
		}
		if (count > mid)
			right = mid;
		else
			left = mid + 1;
	}
	return (left);
}

#include <stdio.h>

int	main(void)
{
	int nums[] = {1, 2, 4, 5, 3, 2};
	int numsSize = 6;

	printf("%d\n", findDuplicate(nums, numsSize));
	return (0);
}
