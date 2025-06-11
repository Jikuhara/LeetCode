# 1046. Last Stone Weight

https://leetcode.com/problems/last-stone-weight/description/

どういう問題か。
石が並んでいる。
最も大きい2つを取り出して、ぶつける。
- 同じ大きさなら2つとも爆散する。
- 大きさが違うなら、大きいほうが小さい方の大きさ分だけ小さくなる。
この操作を石が1つになるまで繰り返す。

必要な操作は、
1. 最も大きい石を2つ取り出す操作。
2. その2つをぶつける操作。

今回の石の数は、1～30個なので、毎回端から端まで走査してもよい。
ソートして大きい2つを取り出すでも良い。

計算量を考える。
毎回走査して、2つ取り出す操作はO(n)。
ぶつける操作はO(1)。
# その後、石が1つになるまで繰り返すので、O(n^2)。

ソートする場合は、O(n log n)。
ぶつける操作はO(1)。
あ、てか、ここで石が残った場合（$x != y$ のとき）ソート済みの配列に挿入する必要がある。

ソートするのは面倒くさそう。毎回操作する方の方が直感的で可読性も良いままかけそうかな。
早速操作の方で実装してみよう。
一番最初に考えた日本語の文章のまま実装すれば上手くいきそう。

## Comments

### step1
```c
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
```
うーん。上手くいかなかった。
原因は2番目の最大値を取得するところ。
このやり方やと、先頭が最大値のとき、2番目の最大値が取得できない。

やっぱり毎回ソートするべきか。。。
挿入するんじゃなくて、毎回ソートしてしまえば良いのかも。
てか最初の発想は実質Insertion Sortを毎回していたのか。
使用するソートは何が良いやろ。ほとんどソート済みやし、Insertion Sortでいっか。
*   

### step2
```c
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
```
Insertion_sortの実装がむずい！
```c
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
```
Sortが実装できてしまえば簡単。

他の人の実装を確認してみる。
software engineering協会で解いている人はいなかった。
LeetCodeの方で見てみる。

LeetCodeも見たけど、C言語でやってる人が少なすぎる😭
やっぱC++習得したほうが良いのかな。。。
ちょっと練習してみようかな。。。
*   

### step3

*   
