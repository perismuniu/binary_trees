#include "binary_trees.h"

/**
 * binary_tree_levelorder - function that goes through a binary
 * tree using level-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1024];
	int front = 0;
	int rear = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left)
		{
			queue[rear++] = current->left;
		}

		if (current->right)
		{
			queue[rear++] = current->right;
		}
	}
}
