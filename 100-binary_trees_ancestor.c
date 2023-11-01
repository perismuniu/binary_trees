#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest common
 * ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return:  pointer to the lowest common ancestor node of the
 * two given nodes or return NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestors[1024];
	size_t first_ancestors = 0;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	while (first != NULL)
	{
		ancestors[first_ancestors++] = (binary_tree_t *)first;
		first = first->parent;
	}

	while (second != NULL)
	{
		for (size_t i = 0; i < first_ancestors; i++)
		{
			if (second == ancestors[i])
			{
				return ((binary_tree_t *)second);
			}
		}
		second = second->parent;
	}
	return (NULL);
}
