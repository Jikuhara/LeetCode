#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> num_to_index;
	for (int i = 0; i < (int)nums.size(); ++i) {
		int complement = target - nums[i];
		if (num_to_index.find(complement) != num_to_index.end()) {
			return {num_to_index[complement], i};
		}
		num_to_index[nums[i]] = i;
	}
	return {};
}

int main() {
	std::vector<int> nums = {2, 11, 3, 4, 6, 7};
	int target = 9;
	std::vector<int> result = twoSum(nums, target);
	std::cout << "Incides : " << result[0] << ", " << result[1] << std::endl;
	return 0;
}
