#include "binary_trees.h"

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * Return: (0) if tree is NULL.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[10000], *current;
	int front = 0;
	int rear = 0;
	bool non_full_node_found = false;

	if (tree == NULL)
	{
		return (0);
	}
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];

		if (non_full_node_found)
		{
			if (current->left != NULL || current->right != NULL)
			{
				return (0);
			}
		}
		if (current->left != NULL)
		{
			queue[rear++] = current->left;
		}
		else
		{
			non_full_node_found = true;
		}
		if (current->right != NULL)
		{
			queue[rear++] = current->right;
		}
		else
		{
			non_full_node_found = true;
		}
	}
	return (1);
}
