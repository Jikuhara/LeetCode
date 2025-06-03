/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:47:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/02 09:55:16 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. 配列の値をそのまま使う
int findDuplicate(int* nums, int numsSize)
{
	int i;
	int first;
	static int numsSize_copy = 4;

	i = 0;
	first = 0;
	while (i < numsSize_copy)
	{
		if (nums[i] < numsSize / 2)
			first++;
		else
			first--;
		i++;
	}
	if (first > 0)
	{
		// 前半側に重複がある
		return findDuplicate(nums, numsSize / 2);
	}
	else
	{
		// 後半側に重複がある
		return findDuplicate(nums, numsSize - numsSize / 2);
	}
}

#include <stdio.h>

int	main(void)
{
	int nums[] = {1, 2, 3, 3};
	int numsSize = 4;

	printf("%d\n", findDuplicate(nums, numsSize));
	return (0);
}
