# 198. House Robber

https://leetcode.com/problems/house-robber/description/

## Comments

面白そうな問題やなぁ。
ぱっと見、基本偶数番目OR奇数番目を選ぶ感じかなぁ。
けど、そう単純ではなさそうやなぁ。
全探索で全部選んでから比較 OR 更新って感じで実装できそうちゃう？
家の数の最大値は100。
基本的には選ぶ・選ばないの2択やから、時間計算量はO(2^n)。
全然無理か。

とりあえず、全ての家が400(最大値)で100個取れたとしても40000やから出力には問題なさそう。
うーん。
むずいなあ。

樹形図のイメージやと分岐が多すぎて対処できなさそう。
なんとか計算量を減らしたいんやけど、どうやって減らすか。

貪欲法ってどうやるんやっけ。
一回貪欲法の考え方を復習してからやな。
[貪欲法 Wiki](https://ja.wikipedia.org/wiki/%E8%B2%AA%E6%AC%B2%E6%B3%95#:~:text=%E8%B2%AA%E6%AC%B2%E6%B3%95%E3%81%AF%E5%B1%80%E6%89%80%E6%8E%A2%E7%B4%A2,%E5%86%8D%E8%80%83%E3%81%99%E3%82%8B%E4%BA%8B%E3%81%AF%E7%84%A1%E3%81%84%E3%80%82)

なるほど〜。
てかダイクストラ法って貪欲法の一種なんや。学び。

動的計画法っぽく見えてきた。
Nを見るときに、N-1とN-2での最大値を見て、Nを取るかどうか判断すれば行けるんちゃうかな。

具体的に考えると、
N-2のMax＋N と N-1のMaxを比較して、Nを取るかどうか決める感じかな。
最初の1，2は特別扱いして、3からは上の考え方で行けるんちゃうかな。

最終的にはNとN-1のMaxを比較して、全体の最大値を出せば行けそう。

なんかこれグラフ理論っぽく考えれそうやけど、まあいいや。
Step1に書いてみよう。

### step1
```c
#include <stdio.h>
#include <stdlib.h>

int	rob(int *nums, int numsSize)
{
	int	current_sum[2];
	int	take_house;
	int	not_take_house;

	if (numsSize == 0)
	{
		return (0);
	}
	if (numsSize == 1)
	{
		return (nums[0]);
	}
	current_sum[0] = nums[0];
	current_sum[1] = nums[1];
	for (int i = 2; i < numsSize; i++)
	{
		take_house = nums[i] + current_sum[0];
		not_take_house = nums[i - 1];
		if (current_sum[0] < current_sum[1])
			current_sum[0] = current_sum[1];
		if (take_house > not_take_house)
		{
			current_sum[1] = take_house;
		}
		else
		{
			current_sum[1] = not_take_house;
		}
	}
	if (current_sum[1] > current_sum[0])
	{
		return (current_sum[1]);
	}
	else
	{
		return (current_sum[0]);
	}
}

int	main(void)
{
	int	nums[] = {1, 2, 5, 0, 3, 100};
	int	numsSize;

	numsSize = 10;
	// printf("%i\n", rob(nums, numsSize));
	for (int i = 1; i < numsSize; i++)
		printf("%i\n", rob(nums, i));
	return (0);
}
```
できた。入出力はあってそうやし提出する。
![1回目の提出](image.png)

OK.
もうちょいロジックきれいにできそうやなぁ。
あと、変数名もうちょい工夫できそう。
not_take_houseはわかりにくいなぁ。

最大値更新部分は3項演算子使用したほうがわかりやすいか？
*

### step2
```c
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
```
短くはなったけど、あんま好まんなぁ。ちょっと見づらい感ある。

*

### step3
参考にしたコード
[iroafternoonteaさんのコード](https://github.com/irohafternoon/LeetCode/pull/38/files)
[Fuminitonさんのコード](https://github.com/Fuminiton/LeetCode/pull/35/)
[hayashiさんのコード](https://github.com/hayashi-ay/leetcode/pull/48/files)
[fhiyoさんのコード](https://github.com/fhiyo/leetcode/pull/36/files)

他の人のコードを読んでみた。

てかこれ最後のReturn内の比較必要ないやん！！
変数名の`max_money_so_far`めっちゃ良いわ。
合計の変数2つに分けたほうが見やすいかもねー

```c
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
```
やっぱ最後の比較は必要やわ。
うーん、やっぱ全体的に見づらいし、理解も深くなさそう。。。

*
