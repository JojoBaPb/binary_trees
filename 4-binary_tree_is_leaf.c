#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if node is a leaf of the binary tree.
 * @node: Pointer to the node to check.
 * Return: If the node is leaf - 1.
 * Else - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
