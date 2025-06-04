# 543. diameter-of-binary-tree

https://leetcode.com/problems/diameter-of-binary-tree/description/

## Comments
### step1
初めてBinaryTreeの問題やるなぁ。
どういう問題なんやろこれ。
最も長い辺の数を求める問題かな。
仮引数はこれか。
```c
int diameterOfBinaryTree(struct TreeNode* root) 
```
構造体のTreeNodeってやつか。そもそもこいつなんや。

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
```

構造体の中に、更に自分自身が2つはいっているのか。
LinkedListの進化版って感じかな。
どういう風に解くのが良いんやろ。
そもそもBinaryTreeにつながってるって過程は良いのか。Checkすべきなのか。
まあとりあえずは入力が正しいと仮定して進めるか。

最大の辺の数を数えることに注目しよう。
とりあえずは、一番端の頂点から始めて、一番端の頂点で終わらんとあかんなぁ。
どうやってその端と端を見つけるのか。

一番深いところから始めて、そこからまた端を見つけて、計算する？総当たり的な？
けどめっちゃ時間かかりそう。
1023なら、511個の頂点があるから、O(n^2)になるなぁ。

入力10^4までやし、O(n^2)はだいぶ厳しそうやなぁ。てか100％右の頂点と左の頂点しかありえんくない？
大発見したぞこれ。
んで、100％正しい2分木屋と仮定したら、片方の頂点は絶対一番左の頂点やん。
んで、もう片方の頂点は絶対一番右の頂点やん。
いや、それは微妙か。
いや、合ってるか。
え、どうなんやろ。分からんなぁ。一番左にできるだけ行って、なかったら最後右行く感じかなぁ。

だいぶ行けそう。
実装してみるか。

### step2
BinaryTreeのこと勘違いしてそう。
イマイチわからん。。。

とりあえず、調べてみる。
[BinaryTree Wiki](https://ja.wikipedia.org/wiki/%E4%BA%8C%E5%88%86%E6%9C%A8)
[二分木クラスとその応用](http://www.ic.daito.ac.jp/~mizutani/python/binary_tree.html)
[「みんなのデータ構造」で学ぶデータ構造 〜 BinaryTree・BinarySearchTree](https://panda-program.com/posts/data-structure-binary-tree)
[データ構造入門：二分木の仕組みと実装](https://zenn.dev/brainyblog/articles/data-structures-intro-binary-trees)

うーん。いまいち分からん。。
ChatGPTに問題文の翻訳と、具体例を作ってもらおう。

---
```markdown
# LeetCode 543 — Diameter of Binary Tree  
**和訳・具体例まとめ**

---

## メタデータ
- **日時**：2025-06-04 00:34 (JST)  
- **質問内容**：LeetCode 問題 543 “Diameter of Binary Tree” の英語原文 → 日本語訳と具体例の作成  
- **使用モデル**：OpenAI o3  

---

## 日本語訳

### 問題文  
二分木の根 `root` が与えられたとき，その **直径 (diameter)** の長さを返してください。  

**二分木の直径** とは，木の中に存在する任意の 2 つのノード間を結ぶ最長経路の長さを指します。  
この経路は **必ずしも根を通る必要はありません**。  

ノード間の経路の長さは，**2 つのノードを結ぶエッジ（辺）の本数**で表します。

### 制約  
- ノード数 `n` は 1 ≤ `n` ≤ 10⁴  
- ノードの値は −100 ≤ `Node.val` ≤ 100  

---

## 公式サンプル

| 入力 | 出力 | 説明 |
|------|------|------|
| `[1,2,3,4,5]` | `3` | 最長パス `[4,2,1,3]` または `[5,2,1,3]` の辺数 |
| `[1,2]` | `1` | パス `[2,1]` の辺数 |

---
```

## 追加の具体例

### 例 3  
```

入力:  root = \[1,2,3,4,5,6]
1
/    \;
2     3
/ \     \;
4   5     6
出力:  4

```
**理由**  
最長経路は `[4,2,1,3,6]` で，エッジ数は 4。

---

### 例 4  
```

入力:  root = \[1]
出力:  0

```
**理由**  
ノードが 1 つだけの場合，2 点間の経路は存在せず，直径は 0。

---

### 例 5  
```

入力:  root = \[1,2,3,null,null,4,5,6]
1
/  &#x20;
2     3
/&#x20;
4   5
/
6
出力:  5

```
**理由**  
最長経路は `[6,4,3,1,2]` または `[6,4,3,1] → 途中分岐` などで，辺数は 5。

---

> 上記内容は Markdown 形式です。そのまま `.md` ファイルに貼り付けて引用できます。
---



うーん、イマイチやなぁ。
分かりそうで分からん。
片方は一番深いところでいいと思うんやけど、もう片方をどう選べばいいか分からん。
とりあえず諦めて寝るか。
## Memo
[OpenDataStrucure](https://sites.google.com/view/open-data-structures-ja)
これだけ読んで寝よ。

おきた。続きやろ。
やっぱ全然分からんなぁ。
ずっと左で行って、NULLに到達した時点で右に行けばとりあえず一番深いところまでは行けそう。
ただもう1頂点をどうやって見つけるか。。。

むずいなぁ。

OpenDataStructureのBinaryTreeのところを読んでみるか。

Sizeは再帰で数えられるらしい。
子ノードの和を左右から再帰で足し合わせて、親ノードの個数をゲット出来る。

幅優先探索と深さ優先探索の話が出てきた。
こんなのあったなぁ。

深さ優先探索っぽい。えー。
分からん。

解答読むか。。。
[WaveAlchemistさんの543](https://github.com/NobukiFukui/Grind75-ProgrammingTraining/pull/36/files)

微妙に分からん。深さ優先探索っぽい。
[kitakenさんの543](https://github.com/Kitaken0107/GrindEasy/pull/17)

うーん。
直径（diameter）って単語は思ってるより、一般的な用語っぽい。
それでGoogle検索掛けてみるか。

[Zennの記事： 【LeetCode】543. Diameter of Binary Treeを解く](https://zenn.dev/ike_pon/articles/b3da3db472eaafd2474b)

これめちゃくちゃわかりやすい！！
なるほど！左右の木の深さを求めて、左右の深さの和を求めるのか。それらのうちで最大のものが直径になるのか！！

行けそう。やるべきことは、左右の深さを求める。
直径を1頂点ずつ求める。か。

Whileを2回回せば行けそう？
最終的には1回でまとめれそうやけど。

いや、分離してWhileで回すよりかは、再帰で常に今までの最大値と比較して、大きい場合だけ更新するのほうが上手くいきそうやな。


左右の深さを再帰で求めて、それを足した結果が現在の最大値より大きかったら更新する、って手順かな。

出力一致した～。自分でMain書けへんのやばいなぁ。
もう少し上手く書けそうではある。
![一回目の提出結果。](image.png)

### step3

解答の一部を参考にした。
以下引用。
```c
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxDepth(struct TreeNode *root, int *diameter)
{
    int l, r, d;

    if (root == NULL)
        return 0;
    l = maxDepth(root->left, diameter);
    r = maxDepth(root->right, diameter);
    d = l + r;
    if (d > *diameter)
        *diameter = d;
    return 1 + MAX(l, r);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode *root)
{
    int diameter = 0;

    maxDepth(root, &diameter);
    return diameter;
}
```

なんかすげぇ。
インライン展開？初めて見た。
maxDepthの中で、直径も更新していくのか。
おー、なるほど。これやとmaxDepthに1行if文を追加するだけで直径も更新できるのか。
すげぇ。

![2回目の提出結果。]({C9285F2F-236B-4413-8BDE-89D96F81D01A}.png)

0ms！？
こんな計算量ちゃうの！？
全然わかんねぇ。

あーけど、1回目の提出のやつは毎回再帰の中で再帰してるから、O(n^2)になるんか。   
Main関数かけんかったり、計算量分からんかったり、まだまだやなぁ。