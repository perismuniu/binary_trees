#include "binary_trees.h"

/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: (1) if tree is a valid BST, and 0 otherwise.
 * If tree is NULL, return 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min, max;

	min = INT_MIN;
	max = INT_MAX;

	if (tree == NULL)
	{
		return (0);
	}

	return (is_valid_bst_helper(tree, min, max));
}

/**
 * is_valid_bst_helper - function to check if a subtree is a valid BST.
 * @node: Pointer to the root node of the current subtree.
 * @min: Minimum valid value for nodes in the subtree.
 * @max: Maximum valid value for nodes in the subtree.
 * Return: check the left and right subtrees.
 */

int is_valid_bst_helper(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
	{
		return (1);
	}

	if (node->n <= min || node->n >= max)
	{
		return (0);
	}

	return (is_valid_bst_helper(node->left, min, node->n) &&
			is_valid_bst_helper(node->right, node->n, max));
}
