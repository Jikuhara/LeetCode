/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   239_sliding-window-maximum.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:46:17 by kei2003730        #+#    #+#             */
/*   Updated: 2025/06/04 17:59:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
# define DEQUE_CAPACITY 100001
typedef struct s_Deque
{
	int				top;
	int				bottom;
	unsigned int	size;
	int				array[DEQUE_CAPACITY];
}					t_Deque;

 void	deque_init(t_Deque *deque)
{
	deque->top = 0;
	deque->bottom = 0;
	deque->size = 0;
	// bzero(deque->array, sizeof(int) * DEQUE_CAPACITY);
}

void	deque_clear(t_Deque *deque)
{
	deque_init(deque);
}

bool	deque_is_empty(const t_Deque *deque)
{
	return (deque->size == 0);
}

bool	deque_is_full(const t_Deque *deque)
{
	return (deque->size == DEQUE_CAPACITY);
}

int	deque_peek_at_Nth(const t_Deque *deque, unsigned int index)
{
	size_t	position;

	if (index >= deque->size)
		return (0);
	position = (deque->top + index) % DEQUE_CAPACITY;
	return (deque->array[position]);
}

bool	deque_push_front(t_Deque *deque, int num)
{
	if (deque_is_full(deque))
		return (false);
	deque->top = (deque->top - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
	deque->array[deque->top] = num;
	deque->size += 1;
	return (true);
}

bool	deque_push_back(t_Deque *deque, int num)
{
	if (deque_is_full(deque))
		return (false);
	if (deque->size == 0)
	{
		deque->array[deque->top] = num;
		deque->bottom = (deque->top + 1) % DEQUE_CAPACITY;
	}
	else
	{
		deque->array[deque->bottom] = num;
		deque->bottom = (deque->bottom + 1) % DEQUE_CAPACITY;
	}
	deque->size += 1;
	return (true);
}

bool	deque_pop_front(t_Deque *deque, int *out)
{
	if (deque_is_empty(deque))
		return (false);
	if (out)
		*out = deque->array[deque->top];
	deque->top = (deque->top + 1) % DEQUE_CAPACITY;
	deque->size -= 1;
	return (true);
}

bool	deque_pop_back(t_Deque *deque, int *out)
{
	if (deque_is_empty(deque))
		return (false);
	deque->bottom = (deque->bottom - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
	if (out)
		*out = deque->array[deque->bottom];
	deque->size -= 1;
	return (true);
}

int deque_peek_back(t_Deque *deque)
{
    int pos;
	pos = (deque->bottom + DEQUE_CAPACITY - 1) % DEQUE_CAPACITY;
    return (deque->array[pos]);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int i;
	int *result;
	t_Deque deque;

	i = 0;
	*returnSize = numsSize - k + 1;
	result = malloc(sizeof(int) * (*returnSize));
	if (!result)
		return (NULL);
	if(k == 1)
	{
		memcpy(result, nums, sizeof(int) * (*returnSize));
		return (result);
	}
	deque_init(&deque);
	while (i < numsSize)
	{
		while (!deque_is_empty(&deque) && nums[i] >= nums[deque_peek_back(&deque)])
			deque_pop_back(&deque, NULL);
		deque_push_back(&deque, i);
		if (i - deque.array[deque.top] >= k)
        	deque_pop_front(&deque, NULL);
		if (i >= k - 1)
			result[i - k + 1] =nums[deque_peek_at_Nth(&deque, 0)];
		i++;
	}
    return (result);
}
