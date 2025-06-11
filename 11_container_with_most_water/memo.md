# 11. Container With Most Water

https://leetcode.com/problems/container-with-most-water/description/

問題の概要。
二次元の水槽の中に入れれる最大の水の面積を答えよ。って問題。

まず選択肢は、 $\binom{N}{2} = O(N^2)$ 個存在する。

2つのうち、1つを固定する。
それをi番目とする。

もう片方をj番目とする。
そのとき、横幅は、

$$ | i - j | $$

高さは、
$$ \min(height[i], height[j]) $$

そのときの面積は、
$$ | i - j | \cdot \min(height[i], height[j]) $$

とりあえず、見るべきは反対側の初めて、
$$ hegiht[j] \geqq height[i] $$
となる $ j $ （つまり、最大の$ j $） を見つけなければいけない。
それ以上内側は見る必要がない。

また、現在見ている中で最大の面積より低くなる場合は探索する必要はない。
例えば、

$$ N = 5, i = 2 , hegiht[i] = 4, maxS = 100$$
のとき、このときの最大値は高々、12なので、$ j $ を探索する必要はない。

## Comments

### step1
```c
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
```

実装はできたけど、計算量はもうちょい改善できそう。
$時間計算量 = O ( N^2 ) $
どうしたら改善できるか。
他の人のコードを見てみる。

* [shintaroyoshida20の11番](https://github.com/shintaroyoshida20/leetcode/pull/34/files)
* [texthonda28の11番](https://github.com/thonda28/leetcode/pull/16)

左右を動かしていく方法がある。
まずは日本語で構造を整理する。

- 左端と右端を決める。
  - 右端の高さが左端より大きい場合、左端を動かす。
  - 右端の高さが左端より小さい場合、右端を動かす。
- このとき、面積を計算して、最大値を更新する。
- 左端と右端が重なるまで繰り返す。

実装してみる。
### step2

```c
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
```
* だいぶきれいに実装できた。

### step3

*
$$
