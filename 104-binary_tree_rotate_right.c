#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation
 * on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}

	return (right_rotate(tree));
}

/**
 * right_rotate - function to perform the right rotation.
 * @y: pointer to the first node.
 * Return: the new root node after rotation.
 */

binary_tree_t *right_rotate(binary_tree_t *y)
{
	binary_tree_t *x, *temp;

	x = y->left;
	temp = x->right;

	x->right = y;
	y->left = temp;

	x->parent = y->parent;
	y->parent = x;

	if (temp != NULL)
	{
		temp->parent = y;
	}

	return (x);
}
