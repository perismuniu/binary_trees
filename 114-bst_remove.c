#include "binary_trees.h"

/**
 * bst_remove - function that removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where you will
 * remove a node.
 * @value: the value to remove in the tree.
 * Return: A pointer to the new root node after removal.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
	{
		return (root);
	}

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * find_min - Helper function to find the minimum node in a BST.
 * @node: The root node of the tree.
 * Return: The node with the smallest value.
 */

bst_t *find_min(bst_t *node)
{
	bst_t *current;

	current = node;

	while (current && current->left)
	{
		current = current->left;
	}
	return (current);
}
