int max(int a, int b)
{
	if (a > b) {
		return (a);
	}
	else {
		return (b);
	}
}

int min(int a, int b)
{
	if (a < b) {
		return (a);
	}
	else {
		return (b);
	}
}

int maxArea(int* height, int heightSize)
{
	int left = 0;
	int right = heightSize - 1;
	int current_max_area = (right - left) * min(height[left], height[right]);
	while (left < right)
	{
		if (height[left] < height[right]) {
			left++;
		}
		else {
			right--;
		}
		current_max_area = max (current_max_area, (right - left) * min(height[left], height[right]));
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
