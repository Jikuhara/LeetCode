/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46_permutations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:36:14 by kei2003730        #+#    #+#             */
/*   Updated: 2025/06/01 15:15:32 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool	set_null(int **returnColumnSizes, int *returnSize)
{
	*returnSize = 0;
	*returnColumnSizes = NULL;
	return (false);
}

bool	input_validation(int *nums, int numsSize, int *returnSize,
		int **returnColumnSizes)
{
	int	i;
	int	j;

	if (!(0 <= numsSize && numsSize <= 6) || !nums || !returnSize
		|| !returnColumnSizes)
		return (set_null(returnColumnSizes, returnSize));
	i = 0;
	while (i < numsSize)
	{
		if (!(-10 <= nums[i] && nums[i] <= 10))
			return (set_null(returnColumnSizes, returnSize));
		j = i + 1;
		while (j < numsSize)
		{
			if (nums[i] == nums[j])
				return (set_null(returnColumnSizes, returnSize));
			j++;
		}
		i++;
	}
	return (true);
}

int	get_return_size(int numsSize)
{
	int	size;
	int	i;

	size = 1;
	i = 1;
	while (i <= numsSize)
	{
		size *= i;
		i++;
	}
	return (size);
}

int	**allocate_result(int numsSize, int *returnSize, int **returnColumnSizes)
{
	int	**result;
	int	i;

	*returnSize = get_return_size(numsSize);
	result = malloc(sizeof(int *) * (*returnSize));
	if (!result)
		return (NULL);
	*returnColumnSizes = malloc(sizeof(int) * (*returnSize));
	if (!(*returnColumnSizes))
		return (free(result), NULL);
	i = 0;
	while (i < *returnSize)
	{
		result[i] = malloc(sizeof(int) * numsSize);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (free(*returnColumnSizes), NULL);
		}
		(*returnColumnSizes)[i] = numsSize;
		i++;
	}
	return (result);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	generate_permutations(int *nums, int numsSize, int start, int **result,
		int *result_index)
{
	int	i;

	if (start == numsSize)
	{
		memcpy(result[*result_index], nums, sizeof(int) * numsSize);
		(*result_index)++;
		return ;
	}
	i = start;
	while (i < numsSize)
	{
		swap(&nums[start], &nums[i]);
		generate_permutations(nums, numsSize, start + 1, result, result_index);
		swap(&nums[start], &nums[i]);
		i++;
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
	assume caller calls free().
 */
int	**permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int	**result;
	int	*nums_copy;
	int	result_index;
	int	i;

	if (!input_validation(nums, numsSize, returnSize, returnColumnSizes))
		return (*returnSize = 0, *returnColumnSizes = NULL, NULL);
	result = allocate_result(numsSize, returnSize, returnColumnSizes);
	if (!result)
		return (*returnSize = 0, NULL);
	nums_copy = malloc(sizeof(int) * numsSize);
	if (!nums_copy)
	{
		i = 0;
		while (i < *returnSize)
			free(result[i++]);
		return (free(result), free(*returnColumnSizes), NULL);
	}
	memcpy(nums_copy, nums, sizeof(int) * numsSize);
	result_index = 0;
	generate_permutations(nums_copy, numsSize, 0, result, &result_index);
	free(nums_copy);
	return (result);
}

// int	main(void)
// {
// 	int nums[] = {1, 2, 3, 4};
// 	int numSize = 4;
// 	int returnSize;
// 	int *returnColumnSizes;
// 	int **result;
// 	int i;
// 	int j;

// 	result = permute(nums, numSize, &returnSize, &returnColumnSizes);
// 	printf("順列の数: %d\n", returnSize);
// 	printf("すべての順列:\n");
// 	i = 0;
// 	while (i < returnSize)
// 	{
// 		printf("%d: ", i + 1);
// 		j = 0;
// 		while (j < returnColumnSizes[i])
// 			printf("%d ", result[i][j++]);
// 		printf("\n");
// 		i++;
// 	}
// 	i = 0;
// 	while (i < returnSize)
// 		free(result[i++]);
// 	free(result);
// 	free(returnColumnSizes);
// 	return (0);
// }
