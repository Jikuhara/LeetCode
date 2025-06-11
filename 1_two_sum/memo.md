# 1. Two Sum

https://leetcode.com/problems/two-sum/description/

初めてCPPで書いてみる。


## Comments

### step1
```C++
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
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	std::vector<int> result = twoSum(nums, target);
	std::cout << "Indices : " << result[0] << ", " << result[1] << std::endl;

	return 0;
}
```

とりあえず、答え見ながら写して書いてみた。
全体的にC言語と同じ。
#include と、型宣言の書き方が違うくらい。
vectorが便利すぎる。mallocもfreeもしなくていいのすごい。
.find .sizeなどで、一気に個数などを求められるのも便利。
とりあえず、次は見ずに書いてみる。

*

### step2
```c++
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> num_to_index;

	for (int i = 0; i < (int)nums.size() ; ++i) {
		int complement = target - nums[i];
		if (num_to_index.find(complement) != num_to_index.end()) {
			return {num_to_index[complement], i};
		}
		num_to_index[nums[i]] = i;
	}
	return {};
}

int main() {
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	std::vector<int> result =twoSum(nums, target);
	std::cout << "Indices : " << result[0] << ", " << result[1] << std::endl;

	return 0;
}
```

全然見ずに書けなかったので諦め。
やっぱ理解していないところは書けない。
特にunordered_mapの使い方がわからなかった。
これなんや？？？
調べてみる。

[unordered_map - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/unordered_map/unordered_map.html)

hash tableらしい。
今回使用しているのは、intを入れてintを返すモノかな。
うーん、いまいちイメージがつかない。
```c++
	for (int i = 0; i < (int)nums.size() ; ++i) {
		int complement = target - nums[i];
		if (num_to_index.find(complement) != num_to_index.end()) {
			return {num_to_index[complement], i};
		}
		num_to_index[nums[i]] = i;
	}
```
構造的には、for → ifなので、「初めて〇〇したとき」という論理。
今回の問題から逆算すると、おそらく「初めて２つの和がtargetと一致したとき」ということだろう。
ってことは、if文内条件式は、「２つの和が一致したとき」。
この時に、num_to_index[complement]は、complementの値を持つ要素のindexを返す。
そして、iは現在の要素のindex。

うーん、イマイチわからん！！
もう一回書いてみるか。
*

### step3
```c++
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
```
やっぱ、unordered_mapの使い方がわからない。

*
