int max(int a, int b)
{
	if (a > b) {
		return (a);
	}
	else {
		return (b);
	}
}

int maxArea(int* height, int heightSize)
{
	int current_max_area = 0;
	for (int i = 0; i < heightSize; i++)
	{
		if ((heightSize - i) * height[i] >= current_max_area) {
			for (int j = heightSize - 1; j > i; j--)
			{
				if (height[j] >= height[i]) {
					current_max_area = max(current_max_area, (j - i) * height[i]);
					break ;
				}
				else {
					current_max_area = max(current_max_area, (j - i) * height[j]);
				}
			}
		}
	}
	return (current_max_area);
}

#include <stdio.h>

int main(void)
{
	int height[] = {1,8,6,2,5,4,8,3,7};
	int heightSize = 9;
	// int height[] = {10,1,9,11,1,1,1,1,10};
	// int heightSize = 9;
	printf("%i\n", maxArea(height, heightSize));
	return (0);
}
