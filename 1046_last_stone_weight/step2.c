#include <stdio.h>
#include <string.h>

void insertion_sort(int *stones, int stonesSize)
{
	for (int i = 1; i < stonesSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (stones[j] < stones[i])
			{
				int tmp = stones[i];
				memmove(stones + j +  1, stones + j, sizeof (int) * (i - j));
				stones[j] = tmp;
				continue ;
			}
		}
	}
	// for (int i = 0; i < stonesSize; i++)
	// {
	// 	printf("%i : %i \n", i, stones[i]);
	// }
	// puts("");
}

int	lastStoneWeight(int *stones, int stonesSize)
{
	for (int i = 0; i < stonesSize - 1; i++)
	{
		insertion_sort(stones, stonesSize);
		if (stones[0] == stones[1])
		{
			stones[0] = 0;
			stones[1] = 0;
		}
		else
		{
			stones[0] -= stones[1];
			stones[1] = 0;
		}
	}
	return (stones[0]);
}

int main(void)
{
	int	stones[] = {2, 7, 4, 1, 8, 1};
	int stonesSize = 6;
	lastStoneWeight(stones, stonesSize);
	return 0;
}
