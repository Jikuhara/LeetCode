struct				TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

int	getDepth(struct TreeNode *root)
{
	int	leftDepth;
	int	rightDepth;

	if (!root)
		return (0);
	leftDepth = getDepth(root->left);
	rightDepth = getDepth(root->right);
	if (leftDepth > rightDepth)
		return (leftDepth + 1);
	else
		return (rightDepth + 1);
}

int	diameterOfBinaryTree(struct TreeNode *root)
{
	int	leftDepth;
	int	rightDepth;
	int	maxDiameter;
	int	leftDiameter;
	int	rightDiameter;

	if (!root)
		return (0);
	leftDepth = getDepth(root->left);
	rightDepth = getDepth(root->right);
	maxDiameter = leftDepth + rightDepth;
	leftDiameter = diameterOfBinaryTree(root->left);
	rightDiameter = diameterOfBinaryTree(root->right);
	if (leftDiameter > maxDiameter)
		maxDiameter = leftDiameter;
	if (rightDiameter > maxDiameter)
		maxDiameter = rightDiameter;
	return (maxDiameter);
}
