/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:04:50 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/02 15:16:38 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Floyd's Toroise & Hare algorithm
// Cycle detection

int findDuplicate(int* nums, int n)
{
	int tortoize;
	int hare;

	tortoize = 0;
	hare = 0;
	while (1)
	{
		tortoize = nums[tortoize];
		hare = nums[nums[hare]];
		if (tortoize == hare)
			break ;
	}
	tortoize = 0;
	while (1)
	{
		tortoize = nums[tortoize];
		hare = nums[hare];
		if (tortoize == hare)
			break ;
	}
	return (hare);
}


#include <stdio.h>

int	main(void)
{
	int nums[] = {3, 1, 3, 4, 2};
	int numsSize = 5;

	printf("%d\n", findDuplicate(nums, numsSize));
	return (0);
}
