/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int	diameterOfBinaryTree(struct TreeNode *root)
{
	int maxDiameter = 0;

	int leftCount = 0;
	int rightCount = 0;

	struct TreeNode *left = current->left;
	while (left->left)
	{
		left = left->left;
		leftCount++;
	}
	struct TreeNode *right = current->right;
	while (right->right)
	{
		right = right->right;
		rightCount++;
	}
}