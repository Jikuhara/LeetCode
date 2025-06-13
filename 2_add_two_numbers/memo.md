# 2. Add Two Numbers

https://leetcode.com/problems/add-two-numbers/description

C++で書く練習。

どういう問題か。
Linked Listが2つ与えられる。
それぞれのLinked Listは、数字が格納されている。
逆順から読んだ数字を足し合わせ、それをまた逆順にLinked Listにして返す。

解き方。
1. 2つのLinked Listを走査して数字に直す。
2. その数字を足し合わせる。
3. 足し合わせた数字を逆順にLinked Listにして返す。

1について。
これはatoiの感覚で直せそう。

2について。
これは足すだけ。

3について。
これは、itoaの感覚で逆順にLinked Listにしていけば良さそう。

C言語なら書けそうやけど、C++でどう書くかわからん😥

参考にしたコード
[maeken4さんのコード](https://github.com/maeken4/Arai60/pull/5/files)
[ryousuketcさんのコード](https://github.com/ryosuketc/leetcode_arai60/pull/5/files)
→基数を定数で置くかどうかの話おもろい。
[jey makさんのコード](https://github.com/jeymak-trainee/arai60training/pull/2/files)
→意外とJavaも読める。C++と似てる。
[mysteaさんのコード](https://github.com/potrue/leetcode/pull/5/files)
→Pythonで書かれていた。文脈がわかっているから読めるが、初見じゃまだPythonは読めなさそう。
[nktrさんのコード](https://github.com/nktr-cp/leetcode/pull/6/files)
→この方のコードめちゃくちゃ分かりやすい！！！すごい。
逆順に入っている意図を理解できた。計算したい順番で入ってるんかこれ。

自分でかけそう！

## Comments

### step1
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy_head = ListNode();
		ListNode *result_tail = &dummy_head;
		int carry = 0;	
		while (l1 || l2 || carry)
		{
			int value = carry;
			if (l1)
			{
				value += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				value += l2->val;
				l2 = l2->next;
			}
			carry = value / 10;
			value %= 10;

			result_tail->next = new ListNode(value);
			result_tail = result_tail->next;
		}
		return dummy_head.next;
	}
};
```
自分で書こうと思ったが思ったより手が動かなかったので、とりあえず写してみた。
carryが繰り上がりを保持している。
dummy_headは結果のLinked Listの先頭を保持している。
while3つの処理を全部まとめてるの分かりやすい。
俺ならバラバラに走査してしまう。
Cと同じで、CPPも上に構造体の中身を定義しておく必要があるのね。
```cpp
	result_tail->next = new ListNode(value);
```
こんなんしていいの？これ気になった。
今度こそ自分で書けそう！

*   

### step2
```cpp
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy_head = ListNode();
		ListNode *result_tail = &dummy_head;
		int curry = 0;
		while (l1 || l2 || curry)
		{
			int val = curry;
			if (l1)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				val += l2->val;
				l2 = l2->next;
			}
			curry = val / 10;
			val = val % 10;
			result_tail->next = new ListNode(val);
			result_tail = result_tail->next;
		}
		return dummy_head.next;
	}
};
```
自分で書けた！
9分ぐらいかかった。
10出てくるの確かにちょっとだけ気になる。
次は定数で外に出してみよう。


Mainが書けないの良くないなぁ。
Main書く練習もしなあかんけど、しんどいので慣れるまでは写経しよう。
ただ、今回人のコード写してるだけやからちょっとおもしろくない。
自分でかけるようにならんとなぁ。


*   

### step3
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	#define BASE_NUM 10;
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy_head = ListNode();
		ListNode *result_tail = &dummy_head;
		int curry = 0;
		while (l1 || l2 || curry)
		{
			int val = curry;
			if (l1)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				val += l2->val;
				l2 = l2->next;
			}
			curry = val / BASE_NUM;
			val = val % BASE_NUM;
			result_tail = new ListNode(val);
			result_tail = result_tail->next;
		}
		return dummy_head.next;
	}
};
```

なんか通らん。Macroの形が良くないんかな？
```cpp
	result_tail = new ListNode(val);
```
next抜けてた😭
8分で書けた。
*   
