int rob(int* nums, int numsSize)
{
	if (numsSize == 0) {
		return (0);
	}
	if (numsSize == 1) {
		return nums[0];
	}
	int current_sum[2] = {nums[0], nums[1]};
	int take_house;
	int not_take_house;
	for (int i = 2; i < numsSize; i++) {
		take_house = nums[i] + current_sum[0];
		not_take_house = nums[i - 1];
		current_sum[0] = current_sum[1] > current_sum[0] ? current_sum[1] : current_sum[0];
		current_sum[1] = take_house > not_take_house ? take_house : not_take_house;
	}
	return (current_sum[1] > current_sum[0]) ? current_sum[1] : current_sum[0];
}
