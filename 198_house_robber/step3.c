int rob(int* nums, int numsSize)
{
	if (numsSize == 0) {
		return (0);
	}
	if (numsSize == 1) {
		return nums[0];
	}
	int max_money_two_before = nums[0];
	int max_money_one_before = nums[1];
	int take_house;
	int not_take_house;
	for (int i = 2; i < numsSize; i++) {
		take_house = nums[i] + max_money_two_before;
		not_take_house = nums[i - 1];
		max_money_two_before = max_money_one_before > max_money_two_before ? max_money_one_before : max_money_two_before;
		max_money_one_before = take_house > not_take_house ? take_house : not_take_house;
	}
	return (max_money_one_before > max_money_two_before ? max_money_one_before : max_money_two_before);
}
