#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance factor
 * of a binary tree.
 * @tree: pointer to the root node of the tree
 * to measure the balance factor.
 * Return: (0) if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance;
	int left_balance;
	int right_balance;

	if (tree == NULL)
	{
		return (0);
	}

	left_balance = binary_tree_height_A(tree->left);
	right_balance = binary_tree_height_A(tree->right);

	balance = left_balance - right_balance;

	return (balance);
}

/**
 * binary_tree_height_A - function that measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_height_A(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = tree->left ? 1 + binary_tree_height_A(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height_A(tree->right) : 1;

	return  (left_height > right_height ? left_height : right_height);
}
