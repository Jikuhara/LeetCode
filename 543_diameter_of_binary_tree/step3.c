struct				TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

int	getDepth(struct TreeNode *root, int *diameter)
{
	int	leftDepth;
	int	rightDepth;

	if (!root)
		return (0);
	leftDepth = getDepth(root->left, diameter);
	rightDepth = getDepth(root->right, diameter);
	if (leftDepth + rightDepth > *diameter)
		*diameter = leftDepth + rightDepth;
	if (leftDepth > rightDepth)
		return (leftDepth + 1);
	else
		return (rightDepth + 1);
}

int	diameterOfBinaryTree(struct TreeNode *root)
{
	int	diameter;

	if (!root)
		return (0);
	diameter = 0;
	getDepth(root, &diameter);
	return (maxDiameter);
}
