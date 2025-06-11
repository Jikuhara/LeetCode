#include <stdio.h>

int	lastStoneWeight(int *stones, int stonesSize)
{
	int max_index = 0;
	int second_max_index = 0;

	for (int i = 0; i < stonesSize; i++)
	{
		for (int j = 0; j < stonesSize; j++)
		{
			max_index = 0;
			second_max_index = 0;
			if (stones[j] > stones[max_index])
			{
				second_max_index = max_index;
				max_index = j;
			}
			printf("%i max_index : %i, second_max_index : %i\n", j, max_index, second_max_index);
		}
	}
	(void)second_max_index;
	return (stones[0]);
}

int main(void)
{
	int	stones[] = {2, 7, 4, 1, 8, 1};
	int stonesSize = 6;
	lastStoneWeight(stones, stonesSize);
	return 0;
}
