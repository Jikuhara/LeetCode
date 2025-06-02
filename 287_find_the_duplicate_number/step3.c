/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:04:50 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/02 15:09:21 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Floyd's Toroise & Hare algorithm
// Cycle detection

int findDuplicate(int* nums, int n)
{
	int toroize;
	int hare;

	toroize = nums[0];
	hare = nums[0];
	while (1)
	{
		toroize = nums[toroize];
		hare = nums[nums[hare]];
		if (toroize == hare)
			break ;
	}
	toroize = nums[0];
	while (1)
	{
		toroize = nums[toroize];
		hare = nums[hare];
		if (toroize == hare)
			break ;
	}
	return (hare);
}


#include <stdio.h>

int	main(void)
{
	int nums[] = {1, 2, 4, 5, 3, 2};
	int numsSize = 6;

	printf("%d\n", findDuplicate(nums, numsSize));
	return (0);
}
