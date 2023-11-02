#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: the value to search in the tree.
 * Return: A pointer to the node containing the value if found,
 * NULL otherwise.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	if (value == tree->n)
	{
		return ((bst_t *)tree);
	}
	else if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}
	else
	{
		return (bst_search(tree->right, value));
	}
}
